#include <bits/stdc++.h>

using namespace std;
class GitRepo{
public:
	static string master_branch;
	string local;
	vector<string> commit_history;
	vector<string> commit_messages;
	static vector<string> global_history;
	static vector<string> global_messages;
	static void init(string initial)
	{
		master_branch = initial;
		global_history = vector<string> ();
		global_messages = vector<string> ();
	}
	GitRepo ()
	{
		local = master_branch;
	}
	void push(char flag='n')
	{
		if(commit_history.empty()==true)
		{
			return;
		}
		if(commit_history[0]!=master_branch)
		{
			if(flag!='f')
			{
			cout<<"Conflicts have arisen, please resolve them before proceeding"<<endl;
			return;
		}
		}
		for(int i = 0;i<commit_history.size();i++)
		{
			global_history.push_back(commit_history[i]);
			global_messages.push_back(commit_messages[i]);
		}
		cout<<"Changes pushed to remote"<<endl;
		master_branch = commit_history.back();
		commit_history.clear();
		commit_messages.clear();
	}
	void commit(string message, string changed)
	{
		commit_history.push_back(local);
		local = changed;
		commit_messages.push_back(message);
	}
	static GitRepo clone()
	{
		GitRepo cloned;
		return  cloned;
	}
	void print_master()
	{
		cout<<master_branch<<endl;
	}
	void print_local()
	{
		cout<<local<<endl;
	}
};
vector<string> GitRepo::global_history;
vector<string> GitRepo::global_messages;
string GitRepo::master_branch;

int main() {

	//basic functionalities
	//	repo - object of github class
	//	push - function which adds new strings
	//	commit - add a new commit message
	//	fetch - 
	//	clone - sends the current status of the master string
	//	fork
	GitRepo::init("Hello World \n ");
	GitRepo user1;
	GitRepo user2;
	GitRepo user3;
	user1.commit("change Hello to Hi","Hi");
	user1.commit("change Hi to Hello123","Hello123");
	user1.push('f');
	user2.commit("change Hello to Hi","Hi");
	user2.push();
	

}

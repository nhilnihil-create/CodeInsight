#include<iostream>
#include<string>
#include<stack>
using namespace std;

string s;

void solve(){
	stack<char> T;
	for(int i=0;i<s.size();i++){
		if(s[i]=='(' || s[i]=='[')
			T.push(s[i]);
		if(s[i]==')'){
			if(T.empty()){cout<<"no"<<endl;return;}
			if(T.top()=='(') T.pop();
			else{cout<<"no"<<endl;return;}
		}
		if(s[i]==']'){
			if(T.empty()){cout<<"no"<<endl;return;}
			if(T.top()=='[') T.pop();
			else{cout<<"no"<<endl;return;}
		}
	}
	if(T.empty())
		cout<<"yes\n";
	else cout<<"no\n";
}


int main(){

	while(getline(cin,s)){
		if(s==".") break;
		solve();
	}
	return 0;
}
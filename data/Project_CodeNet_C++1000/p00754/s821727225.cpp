#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
	string s;
	while(getline(cin, s), s != "."){
		int flg = 1;
		stack<char> word;
		for(int i=0 ; i < s.size() ; i++){
			if(s[i]=='[') word.push('[');
			if(s[i]=='(') word.push('(');
			if(s[i]==']'){
				if(!word.empty()&&word.top()=='[') word.pop();
				else{
					flg = 0;
				}
			}
			if(s[i]==')'){
				if(!word.empty()&&word.top()=='(') word.pop();
				else{
					flg = 0;
				}
			}
		}
			
			if(flg==1&&word.empty()) cout << "yes" << endl;
			else cout << "no" << endl;
		}
			return 0;
	}
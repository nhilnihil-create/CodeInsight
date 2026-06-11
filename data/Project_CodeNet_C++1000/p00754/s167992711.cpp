#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
	string s;
	while(getline(cin,s)){
		if(s.size()==1 && s[0]=='.')break;
		stack<int>st;
		bool suc=true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='[')st.push(0);
			if(s[i]=='(')st.push(1);
			
			if(s[i]==']'){
				if(st.empty())suc=false;
				else if(st.top()==1)suc=false; 
				else if(st.top()==0)st.pop();
			}
			if(s[i]==')'){
				if(st.empty())suc=false;
				else if(st.top()==0)suc=false;
				else if(st.top()==1)st.pop();
			}
			
		}
		
		if(!st.empty())suc=false;
		if(suc)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
#include<string>
#include<stack>
#include<iostream>
using namespace std;
int main(){
	string s;
	while(getline(cin,s),!(s[0]=='.'&&s.size()==1)){
		int a=0,b=0;
		stack<int> t;
		bool flag=true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				t.push(s[i]);
			}else if(s[i]==')'){
				if(t.empty()||t.top()!='('){
					flag=false;
				}else
				t.pop();
			}else if(s[i]=='['){
				t.push(s[i]);
			}else if(s[i]==']'){
				if(t.empty()||t.top()!='['){
					flag=false;
				}else
				t.pop();
			}
		}
		
		
		if(flag&&!t.size())
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	return 0;
}
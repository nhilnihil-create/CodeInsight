#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char> t;
int main(){
	string s;
	while(getline(cin,s)){
		if(s==".")
		break;
		int m=0,k=0;
		t.push('a');
		for(int i=0;i<s.size();i++){
			if(s[i]=='(' || s[i]=='[')
			t.push(s[i]);
			if(t.top()=='(' && s[i]==')' || t.top()=='[' && s[i]==']')
			t.pop();
			else if(t.top()!='(' && s[i]==')' || t.top()!='[' && s[i]==']'){
				t.push('x');
				break;
			}
		}
		if(t.top()=='a')
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
		
	}
	return 0;
}
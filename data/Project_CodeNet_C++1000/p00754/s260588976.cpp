#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	string n;
	while(getline(cin,n),n!="."){
		stack<char>x;
		bool ans=true;
		for(int i=0;i<n.size();i++){
			char now;
			if(n[i]=='(')x.push(n[i]);
			if(n[i]=='[')x.push(n[i]);
		
			if(n[i]==')'){
				if(x.empty()){
					ans=false;
					break;
				}
			now=x.top();
			x.pop();
			if(now!='(')ans=false;
			}
			if(n[i]==']'){
				if(x.empty()){
					ans=false;
					break;
				}
				now=x.top();
				x.pop();
				if(now!='[')ans=false;
			}
		}
		
	if(x.empty()==false)ans=false;
	if(ans)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	}
	return 0;
}
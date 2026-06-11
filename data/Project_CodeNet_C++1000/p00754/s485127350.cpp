#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void solve(){
	string s;
	while(getline(cin,s)&&s!="."){
		stack<char> sk;
		bool ok=true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(')sk.push('(');
			else if(s[i]=='[')sk.push('[');
			else if(s[i]==')'){
				if(sk.size()&&sk.top()=='('){
					sk.pop();
				}
				else{
					ok=false;
					break;
				}
			}
			else if(s[i]==']'){
				if(sk.size()&&sk.top()=='['){
					sk.pop();
				}
				else{
					ok=false;
					break;
				}
			}
		}
		if(ok&&sk.size()==0)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}

int main(){

	solve();

	return 0;
}
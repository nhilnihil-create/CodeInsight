#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(){

	string str;
	while(getline(cin,str)&&str!="."){
		stack<char> s;
		bool f=true;

		for(int i = 0; i < str.size(); i++){
			if(str[i]=='('){
				s.push(str[i]);
			}
			else if(str[i]==')'){
				if(s.empty()){
					f=false;
					break;
				}
				else{
					if(s.top()=='(')
						s.pop();
					else{
						f=false;
						break;
					}
				}
			}
			else if(str[i]=='['){
				//s2.push(1);
				s.push(str[i]);
			}
			else if(str[i]==']'){
				if(s.empty()){
					f=false;
					break;
				}
				else{
					if(s.top()=='['){
						s.pop();
					}
					else{
						f=false;
						break;
					}
				}
			}
		}
		if(f&&s.size()==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}

	return 0;
}
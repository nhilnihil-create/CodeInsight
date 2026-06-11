#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string s;
	
	while(getline(cin,s)){
		
		stack<char> st;
		bool flag=true;

		if(s==".")break;

		for(int i=0;i<s.size();i++){
			char ch=s[i];

			if(ch=='('||ch=='['){
				st.push(ch);
			}
			else if(ch==')'||ch==']'){
				if(st.empty()){
					flag=false;
					break;
				}else if(ch==')'&&st.top()=='('){
					st.pop();
				}else if(ch==']'&&st.top()=='['){
					st.pop();
				}
				else{
					flag=false;
					break;
				}
			}
		}
		if(st.empty()&&flag){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
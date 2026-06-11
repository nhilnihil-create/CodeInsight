#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string str;
	while(getline(cin, str)){
		if(str==".") break;
		stack<char> st;
		for(int i=0;i<str.size();i++){
			if(str[i]=='('||str[i]=='[') st.push(str[i]);
			if(str[i]==')'){
				if(!st.empty()&&st.top()=='(') st.pop();
				else                           st.push(')');
			}
			if(str[i]==']'){
				if(!st.empty()&&st.top()=='[') st.pop();
				else                           st.push(']');
			}
		}
		cout << (st.empty() ? "yes" : "no") << endl;
	}
}
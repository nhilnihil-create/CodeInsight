#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	string s;
	while(true){
		getline(cin, s);
		if(s == ".") break;
		stack<char> st;
		bool ok = true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(') st.push(s[i]);
			if(s[i]==')'){
				if(st.empty() || st.top() != '('){
					ok = false;
				} else {
					st.pop();
				}
			}
			if(s[i]=='[') st.push(s[i]);
			if(s[i]==']'){
				if(st.empty() || st.top() != '['){
					ok = false;
				} else {
					st.pop();
				}
			}
		}
		if(!st.empty()) ok = false;
		cout << (ok ? "yes" : "no") << endl;
	}
}
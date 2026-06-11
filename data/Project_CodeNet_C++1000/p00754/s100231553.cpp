#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	while(1) {
		getline(cin, s);
		if(s.length()==1 && s[0]=='.') break;
		
		bool ok = true;
		stack<int> st;
		for(int i=0; i<s.length() && ok; ++i) {
			if(s[i]=='(') {
				st.push(0);
			}else if(s[i]=='[') {
				st.push(1);
			}else if(s[i]==')') {
				if(st.empty() || st.top()!=0) ok = false;
				st.pop();
			}else if(s[i]==']') {
				if(st.empty() || st.top()!=1) ok = false;
				st.pop();
			}
		}
		cout << (st.empty() && ok ? "yes" : "no") << endl;
	}
	return 0;
}
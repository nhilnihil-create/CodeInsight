#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

const int INF = 100000000;

int main(void) {
	while(1){
		string s;
		getline(cin, s);
		if(s == ".") break;

		stack<char> st;
		bool success = true;
		for(int i=0; i<s.size(); i++){
			if(s[i] == '(' || s[i] == '['){
				st.push(s[i]);
			}
			if(s[i] == ')'){
				if(st.size() == 0){
					success = false;
					break;
				}
				
				char c = st.top();
				st.pop();
				if(c != '(') success = false;
			}
			if(s[i] == ']'){
				if(st.size() == 0){
					success = false;
					break;
				}

				char c = st.top();
				st.pop();
				if(c != '[') success = false;
			}
		}
		if(st.size() != 0) success = false;

		if(success){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}

	}
	
	return 0;
}
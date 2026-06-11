#include <bits/stdc++.h>
using namespace std;

int main(void){
	while(true){
		string s;
		getline(cin,s); // getline() is 便利 -> http://www.ci.seikei.ac.jp/matsumoto/opro/05.pdf
		if(s[0]=='.') break;
		stack<char> st; // push() -> top() -> pop()
		bool err = false;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '(' || s[i] == '['){
				st.push(s[i]);
			}else if(s[i] == ')' || s[i] == ']'){
				if(st.empty() || s[i] != (st.top()=='('?')':']')){
					err = true;
					break;
				}else{
					st.pop();
				}
			}
		}
		if(!err && st.empty()){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
	return 0;
}

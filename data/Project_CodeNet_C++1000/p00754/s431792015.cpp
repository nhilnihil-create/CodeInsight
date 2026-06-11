// AOJ 1173 The Balance of the world
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	bool f;
	string s;
	while(getline(cin, s)){
		if(s == ".") break;
		stack<char> st;
		f = true;
		string::const_iterator it = s.begin();
		for(;it != s.end();++it){
			if(*it == '(' || *it == '['){
				st.push(*it);
			}
			else if(*it == ')'){
				if(st.size() && st.top() == '('){
					st.pop();
				}
				else{
					f = false;
					break;
				}
			}
			else if(*it == ']'){
				if(st.size() && st.top() == '['){
					st.pop();
				}
				else{
					f = false;
					break;
				}
			}
		}
		if(f){
			if(!st.size()) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
	return 0;
}
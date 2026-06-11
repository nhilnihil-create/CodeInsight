#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		if(s == ".") break;
		stack<char> st;
		for(int i = 0;i < s.length();++i){
			if(s[i] == '(' || s[i] == '[') st.push(s[i]);
			else if(s[i] == ')') {
				if(st.size() && st.top() == '(') st.pop();
				else { 
					st.push(s[i]); 
					break; 
				}
			}
			else if(s[i] == ']') {
				if(st.size() && st.top() == '[') st.pop();
				else{
					st.push(s[i]); 
					break; 
				}
			}
		}
		if(!st.size()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
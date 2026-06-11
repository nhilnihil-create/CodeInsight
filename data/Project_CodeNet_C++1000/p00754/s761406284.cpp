#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool check(stack<char>&st){
	stack<bool> s;
	int len=st.size();
	if(st.empty()) return true;
	for(int i=0 ; i<len;++i){
		if(st.top()==')'){
			s.push(true);
			st.pop();
		} else if(st.top()==']'){
			s.push(false);
			st.pop();
		} else if(st.top()=='('){
			if(s.empty()) return false;
			if(s.top()==false) return false;
			s.pop();
			st.pop();
		} else if(st.top()=='['){
			if(s.empty()) return false;
			if(s.top()==true) return false;
			s.pop();
			st.pop();
		}
	}
	if (!s.empty()) return false;
	return true;
}

int main(){
	string s;
	stack<char> st;
	while(1){
		getline(cin , s);
		if (s==".") break;
		for(int i=0;i<s.length();++i){
			if(s[i]=='(') st.push('(');
			if(s[i]=='[') st.push('[');
			if(s[i]==')') st.push(')');
			if(s[i]==']') st.push(']');
			if(s[i]=='.') break;
		}
		if(check(st)){
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
			for(int i=0;!st.empty();++i){
				st.pop();
			}
		}
		s.erase();
	}
	return 0; 
}
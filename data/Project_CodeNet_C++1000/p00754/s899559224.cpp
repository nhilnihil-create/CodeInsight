//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;
#define MAX 300000

int main(){
	string s, str;
	stack<char> st;
	st.push('.');
	while(getline(cin, str)){
		if(str == ".")break;
		while(st.top() != '.')st.pop();
		//cout << str << str.size() << endl;
		for(int i = 0;i < str.size();i++){
			if(str[i] == '[' || str[i] == '('){
				st.push(str[i]);
			}
			if(str[i] == ']' || str[i] == ')'){
				if(st.top() == '(' && str[i] == ')')st.pop();
				else if(st.top() == '[' && str[i] == ']')st.pop();
				else {st.push(']');break;}
			}
		}
		//cout << st.top();
		if(st.top() == '.' && st.top() != ']')
		cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
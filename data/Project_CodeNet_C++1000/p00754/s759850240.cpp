#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

int main(void)
{
	string str;
	while(getline(cin, str) && str != "."){
		bool flag = true;
		stack<char> st;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '(' || str[i] == '[') st.push(str[i]);
		
			if(str[i] == ']'){
				if(st.size() != 0 && st.top() == '[') st.pop();
				else { flag = false; break; }
			}
			if(str[i] == ')'){
				if(st.size() != 0 && st.top() == '(') st.pop();
				else { flag = false; break; }
			}
		}
		if(flag && st.size() == 0) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str), str != "."){
		stack<char> st;
		bool res = true;
		for (int p = 0; p < str.size(); p++){
			if (str[p] == '(' || str[p] == '['){
				st.push(str[p]);
			}
			else if (str[p] == ')' || str[p] == ']'){
				if (st.empty()){
					res = false;
					break;
				}
				char c = st.top(); st.pop();
				if ((c == '(' && str[p] == ']') || 
				    (c == '[' && str[p] == ')')){
					res = false;
					break;
				}
				
			}
		}
		printf(res && st.empty() ? "yes\n" : "no\n");
	}
	
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main() {
	string s;
	while (getline(cin, s), s != ".") {
		stack<char>st;
		bool flag = true;
		for (char c : s) {
			if (c == '[' || c == '(')
				st.push(c);
			if (c == ']') {
				if (st.size() && st.top() == '[')
					st.pop();
				else {
					puts("no");
					flag = false;
					break;
				}
			}
			if (c == ')') {
				if (st.size() && st.top() == '(')
					st.pop();
				else {
					puts("no");
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			if (st.size())puts("no");
			else puts("yes");
		}
	}
}
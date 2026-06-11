#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	string S;
	while (getline(cin, S)) {
		if (S == ".") break;
		stack<char>sta;
		bool flag = false;
		for (ll i = 0; i < S.size(); i++) {
			if (S[i] == '(') sta.push('(');
			if (S[i] == '[')sta.push('[');
			if (S[i] == ')') {
				if (sta.size() == 0 || sta.top() != '(') {
					flag = true;
					break;
				}
				sta.pop();
			}
			if (S[i] == ']') {
				if (sta.size() == 0 || sta.top() != '[') {
					flag = true;
					break;
				}
				sta.pop();
			}
		}
		if (!flag&&sta.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}


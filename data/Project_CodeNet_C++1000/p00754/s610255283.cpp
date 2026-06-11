#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define EPS 1e-10
using namespace std;
typedef long long llong;

string s;
bool check() {
	stack<char>S;
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		switch (*it) {
		case '(':S.push(*it); break;
		case ')':if (S.empty() || S.top() != '(')return false; S.pop(); break;
		case '[':S.push(*it); break;
		case ']':if (S.empty() || S.top() != '[')return false; S.pop(); break;
		}
	}
	return S.empty();
}

int main() {
	while (getline(cin, s), s != ".") cout << (check() ? "yes" : "no") << endl;
return 0;
}
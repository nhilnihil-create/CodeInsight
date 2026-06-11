#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)

typedef long long ll;
typedef pair<int, int> pii;

string solve(string str)
{
	stack<char> stk;
	char ascii[256];
	ascii[']'] = '[';
	ascii[')'] = '(';

	rep(i, str.size()) {
		if (str[i] == '[' || str[i] == '(')
			stk.push(str[i]);
		if (str[i] == ']' || str[i] == ')') {
			if (stk.size() == 0)
				return "no";
			char ch = stk.top(); stk.pop();
			if (ch != ascii[str[i]])
				return "no";
		}
	}

	return stk.size()==0?"yes":"no";
}

int main(void)
{
	string s;
	for (;;) {
		getline(cin, s);
		if (s[0] == '.') break;

		cout << solve(s) << endl;
	}
	return 0;
}
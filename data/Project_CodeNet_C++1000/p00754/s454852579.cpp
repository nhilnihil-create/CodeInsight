#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define rer(i, a, b) for (int i = (int)a; i <= (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1000000000;
const int mod = 1000000007;
const double eps = 1e-9;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, -1, 0, 1};

int main() {
	string S;
	while (getline(cin, S), S != ".") {
		vector<char> tmp;
		rep(i, S.size()) {
			if (S[i] == '(' || S[i] == ')' || S[i] == '[' || S[i] == ']') tmp.push_back(S[i]);
		}
		stack<char> st;
		bool ans = true;
		rep(i, tmp.size()) {
			if (st.empty() || tmp[i] == '(' || tmp[i] == '[') st.push(tmp[i]);
			else if ((st.top() == '(' && tmp[i] == ')') || (st.top() == '[' && tmp[i] == ']')) st.pop();
			else {
				ans = false;
				break;
			}
		}
		cout << (ans && st.empty() ? "yes" : "no") << endl;
	}
	return 0;
}
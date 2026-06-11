#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

signed main(void)
{
	int k; cin >> k;
	string s; cin >> s;
	int sl = s.length();
	if (k >= sl) cout << s << endl;
	else cout << s.substr(0, k) << "..." << endl;
}

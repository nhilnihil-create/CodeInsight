#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P=pair<int, int>;
typedef long long ll;

signed main(void)
{
	int d, t, s;
	cin >> d >> t >> s;

	cout << (ceil((double)d / s) <= t ? "Yes" : "No") << endl;
	return 0;
}

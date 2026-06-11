#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll a, b, c, d;
	ll cnt, ccnt, dcnt, cdcnt;
	cin >> a >> b >> c >> d;
	cnt = b - a + 1LL;
	ccnt = (b / c) - ((a-1LL) / c);
	dcnt = (b / d) - ((a-1LL) / d);
	cdcnt = (b / ((c*d)/gcd(c,d))) - ((a-1LL) / ((c*d)/gcd(c,d)));
	cout << cnt + cdcnt - (ccnt + dcnt) << endl;
	return 0;
}

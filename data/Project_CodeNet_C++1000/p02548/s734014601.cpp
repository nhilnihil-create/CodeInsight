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
	int n,cnt=1,kake=0,tmp=0;
	ll ans = 0;
	cin >> n;
	REP(i, (int)sqrt(n)) {
		kake = (n - 1) / cnt;
		tmp = kake - i;
		if (1 <= tmp) {
			ans += tmp * 2 + 1;
		}
		else if (tmp == 0) {
			ans += tmp + 1;
		}
		cnt++;
	}
	cout << ans << endl;
	return 0;
}


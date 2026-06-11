#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i < (n); ++i)
#define repk(i,a,n) rep(i,a,n+1)
#define all(v) (v).begin(),(v).end()
typedef pair<int, int> P;
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const ll MOD = 1e9 + 7;
void sol() {
	int cnt = 0;
	int l, r, d; scanf("%d%d%d", &l, &r, &d);
	repk(i, l, r) {
		if (i % d == 0)
			cnt++;
	}
	cout << cnt;
}

int main() {
	int _ = 1;
	// for (scanf("%d", &_); _; _--)
	sol();

	return 0;
}
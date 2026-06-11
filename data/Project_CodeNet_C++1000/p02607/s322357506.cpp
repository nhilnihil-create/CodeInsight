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
	int n; scanf("%d", &n);
	int a[n + 1];
	repk(i, 1, n)scanf("%d", &a[i]);
	repk(i, 1, n) {
		if (i % 2 != 0 && a[i] % 2 != 0)
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
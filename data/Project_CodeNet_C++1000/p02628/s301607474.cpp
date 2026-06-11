#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int p[1500]; 
int main() {
	int n,k; cin >> n >> k;
	rep(i,n) cin >> p[i];
	sort(p,p+n);
	int ans = 0;
	rep(i,k) ans += p[i];
	cout << ans << endl;
	return 0;
}
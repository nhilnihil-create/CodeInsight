#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {
	
	int n;
	string s;
	cin >> n >> s;
	vi lr(n + 1), rw(n + 1);
	rep(i, n) {
		lr[i + 1] = lr[i];
		rw[n - 1 - i] = rw[n - i];
		if (s[i] == 'R')lr[i + 1]++;
		if (s[n - 1 - i] == 'W')rw[n - 1 - i]++;
	}
	
	int ans = INF;
	rep(i, n + 1)ans = min(ans, max(i - lr[i], n - i - rw[i]));
	cout << ans << endl;

}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	vector<int> cnt(3, -1);

	ll ans = 1;
	rep(i,n) {
		int x = v[i] - 1;
		int c = 0;
		rep(j,3) {
			if (x == cnt[j]) c++;
			if (c == 1 && x == cnt[j]) cnt[j]++;
		}
		ans *= c;
		ans %= MOD;
	}
	cout << ans << endl;
}
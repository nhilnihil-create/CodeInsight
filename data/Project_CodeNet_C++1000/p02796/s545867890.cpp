#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	vector<ll> x(n), l(n);
	rep(i,n) cin >> x[i] >> l[i];
	vector<pair<ll, ll>> v(n);
	rep(i,n) {
		v[i].first = x[i] + l[i];
		v[i].second = x[i] - l[i];
	}
	sort(ALL(v));
	ll cur = -LINF;
	int ans = 0;
	rep(i,n) {
		if (cur <= v[i].second) {
			ans++;
			cur = v[i].first;
		}
	}
	cout << ans << endl;
}
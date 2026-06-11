#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll func(ll n) {
	return n * (n - 1) / 2;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	map<ll, ll> mp;
	rep(i,n) mp[v[i]]++;
	ll sum = 0;
	for (auto p: mp) sum += func(p.second);
	rep(i,n) {
		ll m = mp[v[i]];
		cout << sum - func(m) + func(m - 1) << endl;
	} 
}

int main() {
	solve();
	return 0;
}
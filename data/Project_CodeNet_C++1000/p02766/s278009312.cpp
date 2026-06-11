#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
//setprecision(15)

ll beki(ll x, ll n) {
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * x;
	}
	return ans;
}

int main() {
	ll N, K; cin >> N >> K;
	ll cnt = 0;
	while (1) {
		ll b = beki(K, cnt);
		if (b > N) break;
		cnt++;
	}
	cout << cnt << endl;
}
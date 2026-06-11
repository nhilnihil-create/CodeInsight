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
	ll n, k;
	ll a=0,aa=0,sum = 0LL,tmp=0LL;
	ll mod = 1e9+7LL;
	cin >> n >> k;
	vector<ll>arr(n);
	rep(i, n) cin >> arr[i];
	rep(i, n-1)for (int j = i + 1; j < n;j++) if (arr[j] < arr[i])a++;
	rep(i, n)for (int j = 0; j < n; j++)if (arr[j] < arr[i])aa++;
	sum = a * k;
	tmp = aa * (((k * (k - 1LL)) / 2LL)%mod);
	tmp %= mod;
	sum += tmp;
	sum %= mod;
	cout << sum << endl;
	return 0;
}


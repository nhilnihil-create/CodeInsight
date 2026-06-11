#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define acc(v) accumulate(v.begin(), v.end(), 0)

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b){
	if(b==0)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a * b / gcd(a, b);
}

int main()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i, n){
		cin >> a[i];
		a[i] /= 2;
	}
	int count = 0;
	rep(i, n)
	{
		ll tmp = 0;
		while(a[i]%2==0){
			a[i] /= 2;
			tmp++;
		}
		if (i == 0)
		{
			count = tmp;
			continue;
		}
		if(count != tmp){
			cout << 0 << endl;
			return 0;
		}
	}
	ll x = 1;
	rep(i,n){
		x = lcm(x, a[i]);
		if (x > m)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	ll ans = (m / (x * pow(2, count))+1) / 2;
	cout << ans << endl;
}

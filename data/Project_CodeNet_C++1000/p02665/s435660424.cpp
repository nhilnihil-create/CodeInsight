#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define x first
#define y second
#define sz(a) ((int)(a.size()))
const int mod = 1812447359;
const int mod2 = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000;
const int MAX = 200005;
const int ZSUV = 10 * 1000 * 1000;
int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(auto &x : a)
		cin >> x;
	vector<ll> b(n + 1);
	b[n] = a[n];
	for(int i = n - 1; i >= 0; i--)
		b[i] = a[i] + b[i + 1];
	ll ans = 0;
	ll now = 1;
	for(int i = 0; i <= n; i++)
	{
		if(a[i] > now)
		{
			cout << -1;
			return 0;
		}
		ans += now;
		now -= a[i];
		now *= 2;
		if(i != n)
			now = min(now , b[i + 1]);
	}
	cout << ans;
}

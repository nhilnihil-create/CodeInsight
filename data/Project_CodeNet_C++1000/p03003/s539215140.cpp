#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ull mod = 1000000007;

int main(void)
{
	ll n, m;
	cin >> n >> m;
	vector<ll> ss(n);
	rep(i, n) cin >> ss[i];
	vector<ll> ts(m);
	rep(i, m) cin >> ts[i];

	vector<vector<ll>> sum(n + 5, vector<ll>(m + 5, 0));
	rep(i, n) {
		rep(j, m) {
			ll ip = i + 1;
			ll jp = j + 1;
			sum[ip][jp] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
			if (ss[i] == ts[j]) {
				sum[ip][jp] += sum[i][j] + 1;
			}
			sum[ip][jp] += mod;
			sum[ip][jp] %= mod;
		}
	}
	cout << sum[n][m] + 1 << endl;

	return 0;
}

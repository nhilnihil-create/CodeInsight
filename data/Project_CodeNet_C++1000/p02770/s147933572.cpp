#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
//#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
int k, q, d[5678], d1[5678], dsum[5678], d0sum[5678];
signed main() {
	cin >> k >> q;
	for0(i, k)cin >> d[i];
	for1(valsqotch, q) {
		int n, x, m; cin >> n >> x >> m; x %= m;
		for0(i, k) {
			d1[i] = d[i] % m;
			if (!i) {
				dsum[0] = d1[0];
				d0sum[0] = (d1[0] == 0);
			}
			else {
				dsum[i] = dsum[i - 1] + d1[i];
				d0sum[i] = d0sum[i - 1]; if (d1[i] == 0)d0sum[i]++;
			}
		}
		x += dsum[k - 1] * ((n - 1) / k) + dsum[(n - 1) % k - 1];
		cout << n - 1 - x / m - (d0sum[k - 1] * ((n - 1) / k) + d0sum[(n - 1) % k - 1]) << endl;
	}
}
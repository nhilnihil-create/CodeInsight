#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double
#define ll long long

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n), f(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
	sort(a.begin(), a.end());
	sort(f.begin(), f.end());
	int l = -1, r = 1e13;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		int sum = 0;
		for (int i = n - 1; i > -1; i--) {
			int j = n - i - 1;
			if (a[j] * f[i] <= mid) continue;
			else {
				int kek = a[j] * f[i] - mid;
				sum += (kek + f[i] - 1) / f[i];
			}
		}
		if (sum <= k) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r;
	return 0;
}

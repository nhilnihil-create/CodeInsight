#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x)	cout << #x << " " << x << endl;
#define N 2005

typedef long long int ll;
typedef vector<pair<int, int>> vpi;
typedef unordered_map<int, unordered_map<int, int>> ump;

ll dp[N][N];

bool present(ll dp[][N], int l, int r) {
	return dp[l][r] != -1;
}

ll maxHappiness(vpi &v, int cur, int l, int r, ll dp[][N]) {

	if (l > r)
		return 0;

	if (present(dp, l, r))
		return dp[l][r];

	// deb(v[cur].first);
	// deb(v[cur].first * abs(v[cur].second-l));

	ll lmax = maxHappiness(v, cur+1, l+1, r, dp);
	ll rmax = maxHappiness(v, cur+1, l, r-1, dp);

	ll put_in_left = (ll)v[cur].first * abs(v[cur].second-l) + lmax;
	ll put_in_right = (ll)v[cur].first * abs(v[cur].second-r) + rmax;


	// deb();
	// cout << " " << put_in_left << " " << put_in_right << endl;

	dp[l][r] = max(dp[l][r], max(put_in_left, put_in_right));

	return dp[l][r];
}

bool comp(pair<int, int> a, pair<int, int> b) {
	return b.first < a.first;
}

int main() {

	int n;
	cin >> n;
	
	vpi v;
	v.resize(n+1);
	int ip;

	for (int i = 1; i <= n; i++) {
		cin >> ip;
		// v.push_back({ip, i});
		v[i] = {ip, i};
	}

	sort(v.begin()+1, v.end(), comp);

	// for (auto x: v)
	// 	cout << x.first << " " << x.second << ", ";
	// cout << endl;


	memset(dp, -1, sizeof(dp));

	cout << maxHappiness(v, 1, 1, n, dp);

	return 0;
}
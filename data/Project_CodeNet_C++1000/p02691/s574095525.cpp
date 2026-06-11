#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " " << x << "\n";
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define endl "\n"
#define ll long long
#define vi vector<int>

// memset(arr, value, size);


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);

	long t, i, count = 0;
	map<long, long> l, r;
	cin >> t;
	fo(i, t) {
		long a;
		cin >> a;
		r[i - a]++;
		l[i + a]++;
	}

	for (auto el : l) {
		count += el.second * r[el.first];
	}

	cout << count;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()

vector <int> a, sum;



signed main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;

	a.resize(n);sum.resize(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i == 0) sum[i] = a[i];
		else sum[i] = sum[i - 1] + a[i];
	}



	int m = INT_MAX;
	for(int i = 0; i < n; i++) {
		m = min(m, abs(sum[i] - (sum[n - 1] - sum[i])));
	}

	cout << m << endl;
	return 0;
}
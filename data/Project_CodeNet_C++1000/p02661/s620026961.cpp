//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include "bits/stdc++.h"

#define rep(i,n) for(long long (i)=0;(i)<(long long)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define int long long

#define PI (3.14159265358979323)
#define MOD (1000000007LL)
#define INF (1LL<<60LL)
#define MAX_N (10000001)
#define MAX (1000000000000000000LL)
using namespace std;

signed main() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	sort(all(a));
	sort(b.begin(), b.end());
	int ans = 1;
	ans += b[n / 2] - a[n / 2];
	if(n%2==0) {
		ans += b[(n / 2) - 1] - a[(n / 2) - 1];
	}
	cout << ans << endl;
}
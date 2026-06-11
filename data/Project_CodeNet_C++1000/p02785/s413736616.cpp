#include<bits/stdc++.h>
#define int long long
using namespace std;
// ===================== MANASH =================== //

int n,m;

void test() {

	cin >> n;
	int k; cin >> k;
	vector<int> v(n);
	for( int &x : v ) cin >> x;
	sort(v.begin(),v.end(),greater<int>());
	int x = 0;
	for( int i = k; i < n; i++) {
		x += v[i];
	}

	cout << x;

}

signed main() {

	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

	test();
	cout << '\n';
	return 0;

}
#include<bits/stdc++.h>
using namespace std;
// ===================== MANASH =================== //

int n,m;

void test() {

	cin >> n;
	cin >> m;
	int s = 0;
	for( int i = 0; i < m; i++) {
		int x;
		cin >> x;
		s += x;
	}
	cout << ( s >= n ? "Yes" : "No"); 
}

signed main() {

	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

	test();
	cout << '\n';
	return 0;

}
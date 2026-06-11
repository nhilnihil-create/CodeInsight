#include<bits/stdc++.h>
using namespace std;
// ===================== MANASH =================== //

int n,m;

void test() {

	cin >> n;
	cin >> m;
	cout << n/m + (n%m != 0 );
}

signed main() {

	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

	test();

	return 0;

}
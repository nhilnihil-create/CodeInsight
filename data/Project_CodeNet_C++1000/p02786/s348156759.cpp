#include<bits/stdc++.h>
#define int long long
using namespace std;
// ===================== MANASH =================== //

int n,m;
int rec( int x ) {
	if ( x == 0 ) return 0;
	else if ( x == 1 ) return 1;
	else return 1 + 2*rec(x/2);
}
void test() {
	cin >> n;
	cout << rec(n);
}

signed main() {

	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif

	test();
	cout << '\n';
	return 0;

}
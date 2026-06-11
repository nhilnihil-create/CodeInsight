#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define gap ' '
#define L(i) ((i) - (&i))

const int MAXN = 1e7 + 5;
	
int main(){	
	int n, m; cin >> n >> m;
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		ans+=(n-i);
	}
	for(int i = 1; i <= m; ++i){
		ans+=(m-i);
	}
	cout << ans << endl;

	return 0;
}

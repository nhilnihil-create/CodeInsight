#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
	io();
	ull h; cin >> h;
	int pos = 64 - __builtin_clzll(h);
	ull ans = 1;
	for(int i = 0; i < pos - 1; ++i){
		ans <<= 1LL;
		ans |= 1LL;
	}
	cout << ans << '\n';
	return 0;
}
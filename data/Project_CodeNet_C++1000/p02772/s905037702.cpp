#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin());
#define io() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
	io();
	int n; cin >> n;
	bool ok = 1;
	for(int i = 0, x; i < n; ++i){
		cin >> x;
		if(x&1^1){
			ok &= (!(x%3) || !(x%5));
		}
	}
	cout << (ok ? "APPROVED" : "DENIED") << '\n';
	return 0;
}
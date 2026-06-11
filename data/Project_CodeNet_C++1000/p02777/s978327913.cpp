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
	string s, t; cin >> s >> t;
	int a, b;  cin >> a >> b;
	string u; cin >> u;
	if(u == s){
		--a;
	}else{
		--b;
	}
	cout << a << ' ' << b << '\n';
	return 0;
}
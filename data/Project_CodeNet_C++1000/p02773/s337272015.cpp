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
	map<string, int> ump;
	int mx = -1;
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		++ump[s];
		if(ump[s] > mx){
			mx = ump[s];
		}
	}
	for(const auto &x : ump){
		if(x.second == mx) cout << x.first << '\n';
	}
	return 0;
}
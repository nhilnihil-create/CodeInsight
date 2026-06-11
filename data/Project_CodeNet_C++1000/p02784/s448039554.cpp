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
	int h, a; cin >> h >> a;
	int ans = 0;
	vector<int> v(a);
	for(int i = 0; i < a; ++i){
		cin >> v[i];
		ans += v[i];
	}
	cout << (ans >= h ? "Yes" : "No") << '\n';
	return 0;
}
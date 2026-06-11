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
	int n, k; cin >> n >> k;
	vector<ld> v(n);
	vector<ld> sums(n);
	for(auto &x : v) cin >> x;
	sums[0] = v[0];
	for(int i = 1; i < n; ++i){
		sums[i] = v[i] + sums[i - 1];
	}	
	ld mx = -1;
	int idx = 0;
	for(int i = 0; i < n - k; ++i){
		if(sums[i + k] - sums[i] > mx){
			mx = sums[i + k] - sums[i];
			idx = i + 1;
		}
	}
	ld ans = 0;
	for(int i = idx; i < idx + k; ++i){
		ld cur = v[i]*(v[i]+1)/2;
		ans += (cur/v[i]);
	}
	cout << fixed << setprecision(12) << ans << '\n';
	return 0;
}
# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long
  
using namespace std;
  
const int N = 1e3 + 7;
const int mod = 1e9 + 7;

int mx, n, m, q, a[N], b[N], c[N], d[N], vc[N];

void rec( int ind, int x ) {
	vc[ind] = x;
	if ( ind == n ) {
		int cnt = 0;
		for ( int i = 0; i < q; i++ ) {
			if ( vc[b[i]] - vc[a[i]] == c[i] ) {
				cnt += d[i];
			}
		}
		mx = max( mx, cnt );
		return;
	}
	for ( int k = x; k <= m; k++ ) {
		rec( ind + 1, k );
	} 
}

int32_t main() {
    speed;
    cin >> n >> m >> q;
    for ( int i = 0; i < q; i++ ) {
    	cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for ( int i = 1; i <= m; i++ ) {
    	rec( 1, i );
    }
    cout << mx;
}

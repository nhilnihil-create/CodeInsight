# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// # pragma GCC optimize "-O3"
# define int long long
using namespace std;
  
const int N = 1e5 + 7;
const int mod = 1e9 + 7;

int cnt[N];

int binpow( int a, int b ) {
	int r = 1;
	while ( b ) {
		if ( b & 1 ) {
			r = r * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return r;
}

int32_t main() {
    speed;
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for ( int i = k; i > 0; i-- ) {
    	cnt[i] = binpow( k / i, n );
    	for ( int j = i + i; j <= k; j += i ) {
    		cnt[i] = cnt[i] + mod - cnt[j];
    		if ( cnt[i] > mod ) {
    			cnt[i] -= mod;
    		}
    	}
    	// cout << i << ' ' << cnt[i] << '\n';
    	ans = (ans + cnt[i] * i % mod) % mod;
    }
    cout << ans;
}
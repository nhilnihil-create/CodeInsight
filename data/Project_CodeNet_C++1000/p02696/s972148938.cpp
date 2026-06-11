# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long
  
using namespace std;
  
const int N = 1e7 + 7;
const int mod = 1e9 + 7;

int32_t main() {
    speed;
    int a, b, n;
    cin >> a >> b >> n;
    int mx = (a*n)/b - a * (n/b);
    for ( int x = 1; x <= min( 10000000ll, n ); x++ ) {
    	mx = max( mx, (a*x) / b - a * (x/b) );
    }
    for ( int x = n; x >= max( 1ll, n - 10000000ll ); x-- ) {
    	mx = max( mx, (a*x) / b - a * (x/b) );
    }
   	int cnt = 0;
    for ( int x = 10000001; x <= n; x += 1000 ) {
    	mx = max( mx, (a*x) / b - a * (x/b) );
    	cnt++;
    	if ( cnt >= N ) {
    		break;
    	}
    }
    cnt = 0;
    for ( int x = max( 1ll, n - N ); x >= 1; x -= 1000 ) {
    	mx = max( mx, (a*x) / b - a * (x/b) );
    	cnt++;
    	if ( cnt > N ) {
    		break;
    	}
    }
    for ( int x = 10000001; x <= n; x += 100000 ) {
    	mx = max( mx, (a*x) / b - a * (x/b) );
    }
    cout << mx;
}

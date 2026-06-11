/*
ID: sstfmsc1
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
 
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 5
#define MAXS 10000
#define INF 1000000
typedef long long ll;
const char nl = '\n';
ll MOD = (ll)(1e9 + 7);
int modk( int k, int x ) { return ( ( x % k ) + k ) % k; }

void solve()
{
	ll x, k, d; cin >> x >> k >> d;

	ll moves = ll(abs(x) / d);

	if ( moves > k )
	{
		cout << abs( abs(x) - abs(k * d) );
	}
	else
	{
		bool flag = ( ( k - moves ) % 2 == 0 );
		ll ans = abs(x) % d;
		cout << ( (flag) ? ans : min( abs(ans - d), abs(ans + d) ) );
	}
	
	cout << nl;
    return;
}
 
int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("milk2.out", "w", stdout);
    //IOS
	//int q;
    //while( q-- )
    solve();
        
    return 0;
}
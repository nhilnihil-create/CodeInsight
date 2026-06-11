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
    int n; cin >> n;

	vector<int> a(n);

	forin(i, n) cin >> a[i];

	int ans = 0;

	forin(i, n - 2)
	{
		for ( int j = i+1; j < ( n - 1 ); ++j )
		{
			for ( int k = j+1; k < n; ++k )
			{
				int suma = a[i] + a[j] + a[k];
				int maxi = max(a[i], max(a[j], a[k]));
				if ( a[i] != a[j] && a[i] != a[k] && a[j] != a[k]
					&& ( suma - maxi ) > maxi )
				{
					//cout << i+1 << ' ' << j+1 << ' ' << k+1 << nl;
					++ans;
				}
			}
		}
	}

	cout << ans << nl;
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
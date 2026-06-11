/*
ID: sstfmsc1
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
 
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 50000
#define INF 1000000
typedef long long ll;
const char nl = '\n';
ll MOD = (ll)(1e9 + 7);
 
void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    forin(i, n) cin >> a[i];

    ll suma = 0, mayor = 0;
    forin(i, n)
    {
        mayor = max(mayor, a[i]);
        suma += max(0LL, mayor - a[i]);
    }

    cout << suma << nl;
    return;
}
 
int main()
{
    //freopen("milk2.in", "r", stdin);
    //freopen("milk2.out", "w", stdout);
    //IOS
    //int q; cin >> q;
    //while(q--) 
    solve();
        
    return 0;
}
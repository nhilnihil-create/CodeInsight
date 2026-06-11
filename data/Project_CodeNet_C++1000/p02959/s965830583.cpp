#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
using namespace std;
const ll N = 2e5+50, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
ll a[N] , b[N];
int main()
{
    Tsetso
    int n ;
    cin >> n;
    for ( int i = 0 ; i <= n ; i++)
            cin >> a[i] ;
    for ( int i = 0 ; i < n ; i++)
            cin >> b[i] ;
    ll ans = 0 ;
    for ( int i = 0 ; i < n ; i++)
    {
        ans += min(a[i],b[i]);
        b[i] -= min(a[i],b[i]);
        ans += min(a[i+1],b[i]);
        a[i+1] -= min(a[i+1],b[i]);
    }
    cout << ans ;
}

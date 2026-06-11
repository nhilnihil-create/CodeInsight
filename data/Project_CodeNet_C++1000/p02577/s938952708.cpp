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
    string num; 
    cin >> num;

    int suma = 0;
    for(auto x : num) suma += (int)( x - '0' );

    cout << ( ( suma % 9 == 0 ) ? "Yes" : "No" ) << nl;
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
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll INF = 1e18;
const  ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define repd(i,n,init) for(ll i=(n);i>=init;i--)
#define repm(i,m) for(auto i=m.begin();i!=m.end();i++)

int main()
{
    ll X,Y;
    cin >> X >> Y;
    ll ans = 0;
    if(X == 1 && Y == 1){
        ans += 400000;
    }
    if(X <= 3){
        ans += (4-X) * 100000;
    }
    if(Y <= 3){
        ans += (4-Y) * 100000;
    }
    
    cout << ans << endl;
    return 0;
}
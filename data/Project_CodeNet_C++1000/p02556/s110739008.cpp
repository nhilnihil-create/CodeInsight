#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define mod (1000000007)

void solve() 
{
    ll a=INT_MAX,b=-INT_MAX,c=INT_MAX,d=-INT_MAX;
    int n;cin>>n;
    while(n--){
        ll x,y;cin>>x>>y;
        a=min(a,x+y);
        b=max(b,x+y);
        c=min(c,x-y);
        d=max(d,x-y);
    }
    cout<<max(b-a,d-c)<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}
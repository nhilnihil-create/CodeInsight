#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define mod (1000000007)

void solve() 
{
    int a[2010];
    a[0]=1;a[1]=0;a[2]=0;
    rep(i,3,2010)a[i]=(a[i-1]+a[i-3])%mod;
    int s;cin>>s;
    cout<<a[s]<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}
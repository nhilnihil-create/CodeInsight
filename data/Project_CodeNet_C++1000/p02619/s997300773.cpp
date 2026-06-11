#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve()
{
    int d;cin>>d;
    int c[26];REP(i,26)cin>>c[i];
    int s[d][26];REP(i,d)REP(j,26)cin>>s[i][j];
    vector<int>cnt(26,0);
    ll ans=0;
    REP(i,d){
        int t;cin>>t;t--;cnt[t]=-1;
        ans+=s[i][t];
        REP(j,26)cnt[j]++,ans-=cnt[j]*c[j];
        cout<<ans<<endl;
    }
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}
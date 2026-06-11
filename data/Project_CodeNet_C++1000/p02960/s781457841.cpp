#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve()
{
    string s;cin>>s;
    vector<vector<ll> >dp(s.size()+1,vector<ll>(13,0));dp[0][0]=1;
    REP(i,s.size()){
        int x=(s[i]=='?'?-1:s[i]-'0');
        REP(j,10)if(x==-1||x==j)REP(k,13)(dp[i+1][(k*10+j)%13]+=dp[i][k])%=1000000007;
    }
    cout<<dp[s.size()][5]<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}
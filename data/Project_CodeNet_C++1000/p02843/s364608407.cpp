#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll x; cin>>x;
    bool dp[110000];
    dp[0]=true;
    rep(i,x)rep(j,6){
        if(dp[i]==true) dp[i+100+j]=true;
    }
    cout<<dp[x]<<endl;
    return 0;
}
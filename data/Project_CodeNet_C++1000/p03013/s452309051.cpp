#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

const ll MOD=(ll)1e9+7;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m;cin>>n>>m;
    bool state[n+1];mset(state);
    ll d;
    for(int i=0;i<m;i++){
        cin>>d;state[d]=true;
    }
    ll dp[n+1];mset(dp);
    dp[0]=1;
    dp[1]=(state[1]?0:1);
    for(int i=2;i<=n;i++){
        if(state[i]){dp[i]=0;continue;}
        dp[i]=dp[i-2]+dp[i-1];
        dp[i]%=MOD;
    }
    //print(dp);
    cout<<dp[n]<<"\n";
}

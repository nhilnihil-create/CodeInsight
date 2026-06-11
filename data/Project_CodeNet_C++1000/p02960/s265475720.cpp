#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e17;
const long double PI=acos(-1);

string s;
int n;

ll dp[N][15];


ll f(int  idx,int md){
    if(idx==n){
        if(md==5){
            return 1;
        }
        return 0;
    }
    ll &ret=dp[idx][md];
    if(ret!=-1)return ret;
    ret=0;
    if(s[idx]!='?'){
        return ret=f(idx+1,(md*10+(s[idx]-'0'))%13)%MOD;
    }
    for(int i=0;i<10;i++){
        ret+=f(idx+1,(md*10+i)%13)%MOD;
        ret%=MOD;
    }
    return ret;
}

void solve(int T){
    memset(dp,-1,sizeof dp);
    cin>>s;
    n=s.size();
    ll ans=f(0,0);
    cout<<ans<<"\n";
}

int main() {
    fastio
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}




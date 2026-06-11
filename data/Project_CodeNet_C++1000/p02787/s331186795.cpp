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

ll a[1003],b[1003];
int n;
ll dp[10004];

ll f(int h){
    if(h<=0){
        return 0;
    }
    ll &ret=dp[h];
    if(ret!=-1){
        return ret;
    }
    ret=INF;
    for(int i=0;i<n;i++){
        ret=min(ret,f(h-a[i])+b[i]);
    }
    return ret;
}

void solve(int T){
    memset(dp,-1,sizeof dp);
    int h;
    cin>>h>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    cout<<f(h);
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



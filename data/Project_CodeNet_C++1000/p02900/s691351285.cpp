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
const int MOD2=998244353;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e9+7;
const long double PI=acos(-1);

int v=0;

void f(ll x){

    for(ll i=2;i*i<=x;i++){
        bool div=0;
        while(x%i==0){
            div=1;
            x/=i;
        }
        if(div==1){
            v++;
        }
    }
    if(x>=2)v++;
}


void solve(int T){
    ll a,b;
    cin>>a>>b;
    ll g=__gcd(a,b);
    f(g);
    int ans=v;
    cout<<ans+1<<"\n";
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

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

ll RepeatSquaring(ll a, ll n, ll p){
    if(n==0) return 1;
    if(n%2==0){
        ll t = RepeatSquaring(a, n/2, p);
        return t*t % p;
    }
    return (a*RepeatSquaring(a, n-1, p))%p;
}

ll nCr(ll n, ll r, ll mod){
    ll mul = 1, div = 1;
    for(ll i = 0; i < r; i++){
        mul *= n - i;
        div *= i + 1;
        mul %= mod;
        div %= mod;
    }   
    return mul * RepeatSquaring(div, mod - 2, mod) % mod;
}

int main(){
    ll n,k; cin>>n>>k;
    ll ans1,ans2,ans;
    for (int i=1;i<=k;i++){
        if(n-k+1<i){
            cout<<0<<endl;
            continue;
        }
        ans1=nCr(n-k+1,i,mod);
        ans1%=mod;
        ans2=nCr(k-1,i-1,mod);
        ans2%=mod;
        ans=ans1*ans2;
        ans%=mod;
        cout<<ans<<endl;

    }
}










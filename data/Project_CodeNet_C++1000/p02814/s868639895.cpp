#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}


int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    
    rep(i,n){
        cin>>a[i];
        a[i]/=2;
    }

    ll lc=1;
    rep(i,n) lc=lcm(lc,a[i]);

    rep(i,n){
        if((lc/a[i])%2==0){
            cout<<0<<endl;
            return 0;
        }
    }

    ll ans=m/lc;
    ans=(ans+1)/2;
    cout<<ans<<endl;
}

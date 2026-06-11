#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<ll> a(n);

    map<ll,ll> m;
    rep(i,n){
        cin>>a[i];
        m[a[i]]++;
    }

    ll sum=0;
    for(auto e : m){
        sum+=e.second*(e.second-1)/2;
    }
    rep(i,n){
        ll x=m[a[i]];
        ll ans=sum-(x*(x-1)/2-(x-1)*(x-2)/2);
        cout<<ans<<endl;
    }

}


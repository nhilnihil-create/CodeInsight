#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    map<ll,ll> m1,m2;
    rep(i,n){
        ll a;
        cin>>a;
        m1[a+i]++;
        m2[-a+i]++;
    }

    ll ans=0;
    for(auto e : m1){
        ans+=e.second*m2[e.first];
    }

    cout<<ans<<endl;
}
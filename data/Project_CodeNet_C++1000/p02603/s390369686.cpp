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

    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll ans=1000;
    rep(i,n-1){
        if(a[i]<a[i+1]){
            ll kabu=ans/a[i];
            ans-=kabu*a[i];
            ans+=kabu*a[i+1];
        }
    }

    cout<<ans<<endl;
}
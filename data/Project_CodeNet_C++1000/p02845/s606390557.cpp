#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;


int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<ll> cnt(n,0);
    cnt[0]=3;

    ll ans=1;
    rep(i,n){
        ans=(ans*cnt[a[i]])%MOD;
        cnt[a[i]]--;
        cnt[a[i]+1]++;
    }

    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll n,ans=INF; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll sum=accumulate(all(a),0LL);
    ll tmp=0;
    rep(i,n){
        sum -= a[i];
        tmp += a[i];
        ans = min(ans,abs(sum-tmp));
    }
    cout << ans <<endl;
    return 0;
}
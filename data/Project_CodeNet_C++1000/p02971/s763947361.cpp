#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b=a;
    sort(b.rbegin(),b.rend());
    rep(i,n){
        ll ans=b[0];
        if(b[0]==a[i]) ans=b[1];
        cout<<ans<<endl;
    }
    return 0;
}
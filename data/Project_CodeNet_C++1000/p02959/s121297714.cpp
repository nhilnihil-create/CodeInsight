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
    ll n, ans=0;
    cin >> n;
    vector<ll> a(n+1), b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n){
        ll l = min(a[i], b[i]);
        ans += l;
        a[i] -= l;
        b[i] -= l;
        ll r = min(a[i+1], b[i]);
        ans += r;
        a[i+1] -= r;
        b[i] -= r;
    }
    cout << ans << endl;
    return 0;
}
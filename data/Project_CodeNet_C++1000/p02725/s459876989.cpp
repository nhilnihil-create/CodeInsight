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
    ll k, n;
    cin >> k >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    a.push_back(a[0]+k); //ちょうど1周期後
    ll l=0; 
    rep(i,n) l = max(l, a[i+1]-a[i]); //最長の区間を求める
    ll ans = k-l; //求める長さ　＝　周期 - 最長区間
    cout << ans << endl; 
    return 0;
}
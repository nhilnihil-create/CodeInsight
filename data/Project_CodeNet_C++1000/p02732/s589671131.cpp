#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll c2(ll n){
    return n*(n-1)/2;
}

int main(void)
{
    ll n, total=0;
    cin >> n;
    vector<ll> a(n), cnt(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    rep(i,n) total += c2(cnt[i]);
    rep(i,n){
        ll ans = total;
        ans -= c2(cnt[a[i]]);
        ans += c2(cnt[a[i]]-1);
        cout << ans << endl;
    }
    return 0;
}
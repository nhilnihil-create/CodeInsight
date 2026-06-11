#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,d,a;cin>>n>>d>>a;
    vector<pair<ll,ll>> xh;
    xh.resize(n);
    rep(i,n){
        cin>>xh[i].first>>xh[i].second;
    }
    sort(all(xh));
    ll ans = 0;
    queue<pair<ll, ll>> q; //pair<終了点、ダメージ>
    ll tot = 0; //今効果が残っているダメージ

    for(int le=0;le<n;le++){
        ll x=xh[le].first;
        ll h=xh[le].second;
        // ダメージ計算
        while(q.size() && q.front().first < x) {
            tot -= q.front().second;
            q.pop();
        }
        h -= tot; // 効果が残っているダメージをひく

        if(h > 0){
            ll t=(h+a-1)/a;
            ans += t;
            ll damage = t*a;
            tot += damage;
            q.emplace(x+2*d, damage);
        }
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using pll = pair<ll,ll>;
const ll INF64 = 1LL << 60;
const int INF = (1 << 29);

const int m = 2019;

int main(){
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int n = s.size();
    vector<ll> t(200020, 0);
    ll x = 1;
    //mod2019の累積和をとる
    rep(i,n){
        t[i+1] = (t[i]+(ll)(s[i]-'0')*x) % m;
        (x*=10)%=m;
    }
    map<ll, ll> mp;

    //mod2019の累積和の配列の同じ値をカウント
    rep(i,n+1) mp[t[i]]++;
    ll ans = 0;

    //値が同じ物の個数の組み合わせをansに加算
    for(auto p: mp){
        ll x = p.second;
        ans += x*(x-1)/2;
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<ll,ll>;
using v  = vector<ll>;
using vv = vector<v>;
const int MOD = 1000000007;

//爆弾の範囲,強さの予約をqueueで行う

int main(){
    int n;
    ll d,a;
    cin >>n>>d>>a;
    
    vector<P> xh(n);
    rep(i,n){
        cin >>xh[i].first>>xh[i].second;
        xh[i].second = (xh[i].second+a-1)/a;
    }
    sort(xh.begin(),xh.end());
    
    v x,h;
    rep(i,n){
        x.push_back(xh[i].first);
        h.push_back(xh[i].second);
    }
    
    ll tot = 0;
    ll ans = 0;
    queue<pair<ll,ll>> q;
    
    rep(i,n){
        while(q.size() && q.front().first<x[i]){
            tot -= q.front().second;
            q.pop();
        }
        h[i] -= tot;
        if(h[i]>0){
            ans += h[i];
            tot += h[i];
            q.emplace(x[i]+2*d, h[i]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
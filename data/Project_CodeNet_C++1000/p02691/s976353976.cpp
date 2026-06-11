#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecs = vector<string>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

void register_dict(ll x, map<ll,ll> &mp) {
    if(mp.count(x)) mp[x]++;
    else mp[x] = 1;
}

int main() {
    int N; cin >> N;
    vecl A(N); REP(i,N) cin >> A[i];
    map<ll,ll> mp_l,mp_r;
    REP(i,N) {
        int l = -A[i]-(i+1);
        int r = A[i]-(i+1);
        //cout << i + 1 << " "<< l << " " << r << endl;
        register_dict(l,mp_l);
        register_dict(r,mp_r);
    }
    ll ans = 0;
    for(auto p : mp_l) {
        auto x = p.first;
        auto cnt = p.second;
        if(mp_r.count(x)) ans += cnt*mp_r[x];
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

ll solve(ll n, vi const &a, string s){
    set<ll> base;
    for(ll i=n-1; i>=0; i--){
        ll x = a[i];
        set<ll>::reverse_iterator it = base.rbegin();
        while(it != base.rend()){
            ll num = *it++;
            if(x < (x^num)) continue;
            x ^= num;
        }
        if(x != 0){
            if(s[i] == '0') base.insert(x);
            else return 1;
        }
    }
    return 0;
}

int main(){
    Init();
    // テストケースの個数
    ll t; cin >> t;
    while(t--){
        // 初期入力
        ll n; cin >> n;
        vi a(n);
        rep(i, n) cin >> a[i];
        string s; cin >> s;
        cout << solve(n, a, s) << endl;
    }
}
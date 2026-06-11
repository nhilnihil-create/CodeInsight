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

int main(){
    Init();
    ll n; string s;
    cin >> n >> s;
    map<char, ll> cnt;
    rep(i, n) cnt[s[i]]++;
    ll total = cnt['R'] * cnt['G'] * cnt['B'];

    // 条件に合わない個数を数える
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            ll k = 2*j-i;
            if(k > n-1) break;
            if(s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) total--;
        }
    }
    cout << total << endl;
}
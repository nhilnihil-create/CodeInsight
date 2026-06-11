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


// Z-Algorithm; 最長共通接頭辞
// ：文字列sとs[i, s|s|]の最長共通接頭辞の長さを返す。[O(|s|)]
vector<long long> z_algorithm(const string &s){
    vector<long long> prefix(s.size());
    for(long long i=1, j=0; i<(long long)s.size(); i++){
        if(i+prefix[i-j] < j+prefix[j]) prefix[i] = prefix[i-j];
        else{
            long long k = max(0LL, j+prefix[j]-i);
            while(i+k < (long long)s.size() && s[k] == s[i+k]) k++;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = (long long)s.size();
    return prefix;
}

int main(){
    Init();
    ll n, ans = 0; string s; cin >> n >> s;

    // 開始文字をi文字目とした部分文字列で最長共通接頭辞を求める
    for(ll i=0; i<n-1; i++){
        string tmp = s.substr(i);
        // z-algorithm
        auto lcp = z_algorithm(tmp);
        // 重なりが生じないように最長共通部分列を求める
        for(ll j=0; j<lcp.size(); j++) chmax(ans, min(lcp[j], j));
    }
    cout << ans << endl;
}
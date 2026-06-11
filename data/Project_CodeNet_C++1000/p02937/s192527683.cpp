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
    map<char, vector<ll>> pos;
    string s, t; cin >> s >> t;
    rep(i, s.size()){
        pos[s[i]].push_back(i+1);
    }

    ll ans = 0, cur = 0;
    rep(i, t.size()){
        // sに含まれない文字がtに含まれている場合は何個連結しても無理
        if(!pos[t[i]].size()){
            cout << -1 << endl;
            return 0;
        }

        // 前回参照した位置より右にあるかどうか
        auto it = upper_bound(all(pos[t[i]]), cur);
        if(it != pos[t[i]].end()){
            ans += (*it - cur);
            cur = *it;
        }
        else{
            ans += s.size()-cur+pos[t[i]][0];
            cur = pos[t[i]][0];
        }
    }
    cout << ans << endl;
}
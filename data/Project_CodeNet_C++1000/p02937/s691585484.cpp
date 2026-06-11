#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s, t; cin >> s >> t;

    vector<vector<int>> place(26);
    rep(i, s.size()){
        place[s[i] - 'a'].push_back(i);
    }

    ll index = -1, lap = 0;
    bool ok = true;
    rep(i, t.size()){
        vector<int>& p = place[t[i] - 'a'];
        if(p.size() == 0){ ok = false; break; }

        int num = upper_bound(all(p), index) - p.begin();
        if(num == p.size()){
            index = -1; lap++;
            num = upper_bound(all(p), index) - p.begin();
        }
        index = p[num];
    }
    ll res;
    ok ? res = s.size() * lap + index + 1 : res = -1;
    cout << res << ln;
}



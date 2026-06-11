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


int main() {
    string s, t; cin >> s >> t;

    map<char, set<int>> place;
    rep(i, s.size()){
        place[s[i]].insert(i);
    }

    ll index = -1, lap = 0;
    bool ok = true;
    rep(i, t.size()){
        char c = t[i];
        set<int>& st = place[c];
        if(st.size() == 0){ ok = false; break; }

        auto num = st.upper_bound(index);
        if(num == st.end()){
            index = -1; lap++;
            num = st.upper_bound(index);
        }
        index = *num;
    }
    ll res;
    ok ? res = s.size() * lap + index + 1 : res = -1;
    cout << res << ln;
}



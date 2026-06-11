#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
static const llint INF = 1e18;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    string s, t;
    cin >> s >> t;

    unordered_map<char, vector<int>> mp;
    llint ns = s.size(), nt = t.size();
    for(llint is=0;is<ns;++is) {
        char cs = s[is];
        mp[cs].push_back(is);
    }
    for(llint it=0;it<nt;++it) {
        char ct = t[it];
        if(mp.count(ct)==0) {
            cout << -1 << endl;
            return 0;
        }
    }

    llint ans = 0;
    int now = 0;
    for(llint it=0;it<t.size();++it) {
        char c = t[it];
        auto itr = lower_bound(mp[c].begin(), mp[c].end(), now);
        if(itr==mp[c].end()) {
            ans += ns - now;
            now = mp[c][0] + 1;
            ans += now;
        }
        else {
            ans += *itr - now + 1;
            now = *itr + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}

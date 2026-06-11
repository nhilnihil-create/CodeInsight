#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    string former,back;
    int query; cin >> query;
    bool is_reversed = false;
    vector<pair<bool,char>> sec_query;
    REP(_,query) {
        int q; cin >> q;
        if(q == 1) is_reversed = !is_reversed;
        else {
            int f;
            char c;
            cin >> f >> c; f--;
            sec_query.emplace_back(f,c);
            bool is_back = f ^ is_reversed;
            if(!is_back) former.insert(former.begin(),c);
            else back.push_back(c);
        }
    }
    auto x = former+s+back;
    if(is_reversed) reverse(ALL(x));
    cout << x << endl;
}

int main() {
    solve();
    return 0;
}
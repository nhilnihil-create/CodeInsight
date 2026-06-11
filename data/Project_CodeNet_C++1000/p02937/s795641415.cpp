#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const int mod = 1e9 + 7;

int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> a(26, vector<int>());
    rep (i, s.size()) {
        int p = s[i] - 'a';
        a[p].push_back(i);
    }
    int now = 0;
    rep (i, t.size()) {
        int spos = -1;
        while (true) {
            int alp = t[now] - 'a';
            if (a[alp].empty()) {
                cout << -1 << endl;
                exit(0);
            }
            if (upper_bound(all(a[alp]), spos) == a[alp].end()) {
                break;
            }
            int spos_new = *upper_bound(all(a[alp]), spos);
            if (spos_new < spos) {
                break;
            }
            spos = spos_new;
            now++;
            if (now == t.size()) {
                cout << 1ll * i * s.size() + spos + 1 << endl;
                exit(0);
            }
        }
    }
}



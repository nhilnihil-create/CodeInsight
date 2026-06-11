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



int main() {
    string s;
    cin >> s;
    reverse(all(s));
    vector<int> p(s.size() + 1, 0);
    int ten = 1;
    rep (i, s.size()) {
        p[i+1] = p[i] + ten * (s[i] - '0');
        p[i+1] %= 2019;
        ten *= 10;
        ten %= 2019;
    }
    map<int, int> m;
    rep (i, p.size()) {
        m[p[i]]++;
    }
    ll ans = 0;
    for (auto au: m) {
        ll val = au.second;
        ans += val * (val - 1) / 2;
    }
    cout << ans << endl;
}



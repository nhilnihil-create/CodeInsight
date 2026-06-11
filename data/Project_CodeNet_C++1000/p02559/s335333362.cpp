
/**
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */

#include <bits/stdc++.h>
using namespace std;

const bool ready = [](){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(12);
    return true;
}();

const double PI = acos(-1);
using ll= long long;
//#define int ll
#define all(v) (v).begin(), (v).end()
#define fori(n) for(int i=0; i<int(n); i++)

#define cini(i) int i; cin>>i;
#define cins(s) string s; cin>>s;
#define cind(d) double d; cin>>d;
#define cinai(a,n) vi a(n); fori(n) { cin>>a[i]; }
#define cinas(s,n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a,n) vd a(n); fori(n) { cin>>a[i]; }

using pii= pair<int, int>;
using pdd= pair<double, double>;
using vd= vector<double>;
using vb= vector<bool>;
using vi= vector<int>;
using vvi= vector<vi>;
using vs= vector<string>;

#define endl "\n"


/** stolen from tourist, Problem D, https://codeforces.com/contest/1208/standings/page/1 */
template <typename T>
struct fenwick {
    vector<T> fenw;
    int n;

    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }

    /* update add */
    void update(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }

    /* get sum of range (0,x), including x */
    T query(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

void solve() {
    cini(n);
    cini(q);
    
    fenwick<ll> fen(n);
    for(int i=0; i<n; i++) {
        cini(a);
        fen.update(i,a);
    }

    for(int i=0; i<q; i++) {
        cini(t);
        if(t==0) {
            ll p,x;
            cin>>p>>x;
            fen.update(p,x);
        } else {
            ll l,r;
            cin>>l>>r;
            cout<<fen.query(r-1)-fen.query(l-1)<<endl;
        }
    }
}

signed main() {
    solve();
}

// FIRST THINK, THEN CODE
// DO NOT JUMP BETWEEN PROBLEMS

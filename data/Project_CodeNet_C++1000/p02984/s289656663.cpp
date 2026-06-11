#include <bits/stdc++.h>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr int INF = 1001001001;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep (i, n) cin >> a[i];
    
    vector<int> x(n, 0);
    ll t = 0;
    rep (i, n) t += (i % 2 == 0) ? a[i]*2 : -a[i]*2;
    x[0] = t/2;
    rep (i, 1, n) x[i] = a[i-1]*2 - x[i-1];
    rep (i, n) cout << x[i] << " ";
    cout << endl;
    
    return 0;
}

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
    int n;
    cin >> n;
    vector<P> v(n);
    rep (i, n) {
        int x, l;
        cin >> x >> l;
        int s = x - l;
        int t = x + l;
        v[i] = make_pair(t, s);
    }
    sort(all(v));
    int ans = 0;
    int nowt = -2e9;
    rep (i, n) {
        if (nowt <= v[i].second) {
            ans++;
            nowt = v[i].first;
        }
    }
    cout << ans << endl;
}

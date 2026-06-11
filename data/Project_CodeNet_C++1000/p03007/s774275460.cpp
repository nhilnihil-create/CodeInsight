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

const int mod = 1e9+7;




int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mi = 1e9;
    int ma = -1e9;
    rep (i, n) {
        cin >> a[i];
    }
    sort(all(a));
    int M = a[a.size()-1];
    int m = a[0];
    vector<int> x, y;
    rep (i, 1, n-1) {
        if (a[i] < 0) {
            x.push_back(M);
            y.push_back(a[i]);
            M -= a[i];
        } else {
            x.push_back(m);
            y.push_back(a[i]);
            m -= a[i];
        }
    }
    x.push_back(M);
    y.push_back(m);
    M -= m;
    cout << M << endl;
    rep (i, n-1) {
        cout << x[i] << " " << y[i] << endl;
    }

}



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
    ll n;
    cin >> n;
    vector<ll> a(n+2, 0);
    ll sum = 0;
    rep (i, n+1) {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> b(n+1);
    if (a[0] > 0) {
        if (a[0] > 1) {
            cout << -1 << endl;
            exit(0);
        } else {
            if (sum == 1) {
                cout << 1 << endl;
                exit(0);
            } else {
                cout << -1 << endl;
                exit(0);
            }
        }
    }
    b[0] = 1;
    sum -= a[0] + a[1];
    rep (i, n-1) {
        if (2 * b[i] - a[i+1] < 0) {
            cout << -1 << endl;
            exit(0);
        } else {
            ll x = min(2 * b[i] - a[i+1], sum);
            b[i+1] = x;
            sum -= a[i+2];
        }
    }
    if (2 * b[n-1] - a[n] < 0) {
        cout << -1 << endl;
        exit(0);
    }
    b[n] = 0;
    cout << accumulate(all(a), 0ll) + accumulate(all(b), 0ll) << endl;
}
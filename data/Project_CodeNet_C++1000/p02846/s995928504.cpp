//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t1, t2;
    cin >> t1 >> t2;
    ll a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    if(t1*a1+t2*a2 == t1*b1+t2*b2) {
        cout << "infinity" << endl;
        return 0;
    }

    if(t1*a1+t2*a2 > t1*b1+t2*b2) {
        if(a1 > b1) {
            cout << 0 << endl;
            return 0;
        }
        ll hh = t1*a1+t2*a2 - (t1*b1+t2*b2);
        ll sa = t1*(b1-a1);
        cout << sa/hh*2+(sa%hh ? 1:0) << endl;
        return 0;
    }
    if(a1 < b1) {
        cout << 0 << endl;
        return 0;
    }
    ll hh = -(t1*a1+t2*a2) + (t1*b1+t2*b2);
    ll sa = t1*(a1-b1);
    cout << sa/hh*2+(sa%hh ? 1:0) << endl;
    return 0;
}
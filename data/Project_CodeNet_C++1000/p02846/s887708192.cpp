#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;
 
int main() {
    int t1, t2; cin >> t1 >> t2;
    ll a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    if (a1 > b1 && a2 < b2) {
        if (b1 * t1 + b2 * t2 - (a1 * t1 + a2 * t2) < 0) {
            cout << 0 << endl;
            return 0;
        }
        else if (b1 * t1 + b2 * t2 - (a1 * t1 + a2 * t2) == 0) {
            cout << "infinity" << endl;
            return 0;
        }
        double k = 1.0*(a1 - b1)*t1 / ((b2 - a2)*t2 + (b1 - a1)*t1);
        if ((a1 - b1)*t1 % ((b2 - a2)*t2 + (b1 - a1)*t1) != 0) {
            cout << ll(2LL * ll(k)) + 1 << endl;
        }
        else {
            cout << ll(2LL * ll(k)) << endl;
        }
    }
    else if (a1 < b1 && a2 > b2) {
        swap(a1, b1);
        swap(a2, b2);
        if (b1 * t1 + b2 * t2 - (a1 * t1 + a2 * t2) < 0) {
            cout << 0 << endl;
            return 0;
        }
        else if (b1 * t1 + b2 * t2 - (a1 * t1 + a2 * t2) == 0) {
            cout << "infinity" << endl;
            return 0;
        }
        double k = 1.0*(a1 - b1)*t1 / ((b2 - a2)*t2 + (b1 - a1)*t1);
        if ((a1 - b1)*t1 % ((b2 - a2)*t2 + (b1 - a1)*t1) != 0) {
            cout << ll(2LL * ll(k)) + 1 << endl;
        }
        else {
            cout << ll(2LL * ll(k)) << endl;
        }
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
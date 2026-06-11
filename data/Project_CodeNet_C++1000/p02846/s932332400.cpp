#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll p1 = A1 * T1 + A2 * T2;
    ll p2 = B1 * T1 + B2 * T2;
    if (p1 == p2) {
        cout << "infinity" << endl;
    } else {
        if (p1 < p2) {
            swap(A1, B1);
            swap(A2, B2);
            swap(p1, p2);
        }
        ll ans = 0;
        if (B1 > A1) {
            ll maxd = (B1 - A1) * T1;
            ans = 1 + 2 * (maxd / (p1 - p2));
            if (maxd % (p1 - p2) == 0) {
                --ans;
            }
        }
        cout << ans << endl;        
    }
 
    return 0;
}
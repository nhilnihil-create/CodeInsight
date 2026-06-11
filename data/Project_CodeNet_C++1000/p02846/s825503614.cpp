#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    //自明なケース
    if(a1 > b1 && a2 > b2) {
        cout << 0 << endl;
        return 0;
    }
    if(a1 < b1 && a2 < b2) {
        cout << 0 << endl;
        return 0;
    }
    ll c1 = (a1 - b1) * t1, c2 = (a2 - b2) * t2;
    if(c1 + c2 == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    if(c1 > 0 && c1 + c2 > 0) {
        cout << 0 << endl;
        return 0;
    }
    if(c1 < 0 && c1 + c2 < 0) {
        cout << 0 << endl;
        return 0;
    }
    ll itv = abs(c1 + c2);
    /*
    for(int i = 0; i < 120; i++) {
        if(i % 2 == 0) {
            cout << i / 2 * (c1 + c2) << " ";
        } else {
            cout << (i + 1) / 2 * c1 + (i - 1) / 2 * c2 << " ";
        }
    }
    cout << endl;
    */
    if(abs(c1) % itv != 0) {
        cout << abs(c1) / itv * 2 + 1 << endl;
    } else {
        cout << abs(c1) / itv * 2 << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t1,t2,a1,a2,b1,b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    a1 *= t1;
    a2 *= t2;
    b1 *= t1;
    b2 *= t2;
    a2 += a1;
    b2 += b1;
    if(a2 == b2) {
        cout << "infinity" << '\n';
        return 0;
    }
    if(a2 < b2) {
        swap(a1, b1);
        swap(a2, b2);
    }

    if(a1 > b1) {
        cout << 0 << '\n';
        return 0;
    }

    ll c = b1-a1;
    ll d = a2-b2;

    // how many turns c can catch up d
    cout << c/d*2 + (c%d>0) << '\n';

    return 0;
}
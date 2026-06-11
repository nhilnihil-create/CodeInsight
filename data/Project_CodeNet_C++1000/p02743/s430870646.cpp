#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll a, b, c; cin >> a >> b >> c;
    ll cab = c - a - b;
    if (cab > 0 && 4 * a * b < cab * cab) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main() {
    ll A; cin >> A;
    long double B; cin >> B;
    int C = (B+0.000001) * 100;
    ll D = A*C;
    string E = to_string(D);
    if (E.size() <= 2 || A*B < 1) {
        ll F = A*B;
        cout << F << endl;
        return 0;
    }

    for (int i = 0; i < E.size() - 2; i++) {
        cout << E[i];
    }
    cout << endl;
}
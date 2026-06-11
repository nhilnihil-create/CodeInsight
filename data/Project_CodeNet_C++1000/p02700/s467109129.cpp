#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, c, d; cin >> a >> b >> c >> d;
    bool takaAttack = true;
    while (0 < a || 0 < c) {
        if (takaAttack) {
            c -= b;
            takaAttack = false;
        }
        else {
            a -= d;
            takaAttack = true;
        }
    }
    if (!takaAttack) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
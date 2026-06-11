#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll T1, T2; cin >> T1 >> T2;
    ll A1, A2; cin >> A1 >> A2;
    ll B1, B2; cin >> B1 >> B2;
    A1 = A1 * T1; A2 = A2 * T2;
    B1 = B1 * T1; B2 = B2 * T2;

    ll P = A1 - B1;
    ll Q = A2 - B2;
    if (P > 0) {
        P *= -1;
        Q *= -1;
    }
    if (P + Q < 0) {
        cout << 0 << endl;
    } else if(P + Q == 0) {
        cout << "infinity" << endl;
    } else {
        if (P % (P + Q) == 0) {
            cout << -1 * P / (P + Q) * 2 << endl;
        } else {
            cout << -1 * P / (P + Q) * 2 + 1 << endl;
        }
    }
}
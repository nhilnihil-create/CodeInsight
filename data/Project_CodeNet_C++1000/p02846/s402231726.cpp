#include <bits/stdc++.h>
 
using namespace std;

long long t1, t2, a1, a2, b1, b2;

int main() {
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
        cout << "infinity\n";
        return 0;
    }
    if (t1 * a1 + t2 * a2 < t1 * b1 + t2 * b2) {
        swap(a1, b1); swap(a2, b2);
    } 
    if (a1 > b1) {
        cout << "0\n";
        return 0;
    }

    long long q1 = t1 * (b1 - a1);
    long long q2 = (t1 * a1 + t2 * a2) -  (t1 * b1 + t2 * b2);
    long long ans = q1 / q2;
    ans *= 2;
    if (q1 % q2 != 0) ans++;
    cout << ans << '\n';
}
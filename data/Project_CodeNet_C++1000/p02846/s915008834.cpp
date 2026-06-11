#include <bits/stdc++.h>
using namespace std;
int main () {
    long long T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    long long a1 = A1*T1, a2 = A2*T2, b1 = B1*T1, b2 = B2*T2;
    if (a1+a2 == b1+b2) {
        puts("infinity");
        return 0;
    }
    if (a1 < b1) {
        swap(a1, b1);
        swap(a2, b2);
    }
    // a1 > b1
    if (a1+a2 > b1+b2) {
        puts("0");
        return 0;
    }
    // a1+a2 < b1+b2
    long long c = (b1+b2)-(a1+a2);
    long long ans = 1;
    ans += ((a1-b1) / c) * 2;
    if ((a1-b1) % c == 0) {
        ans--;
    }
    cout << ans << endl;
}
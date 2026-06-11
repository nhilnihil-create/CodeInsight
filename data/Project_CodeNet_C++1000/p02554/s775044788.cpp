#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long waru = 1000000007;
    long long ans = 0;
    cin >> num;

    long long a = 1;
    long long bc = 1;
    long long d = 1;
    // ans += pow(10, num);
    for (int i = 0; i < num; i++) {
        a *= 10;
        a %= waru;
    }
    // ans -= pow(9, num);
    // ans -= pow(9, num);
    for (int i = 0; i < num; i++) {
        bc *= 9;
        bc %= waru;
    }
    // ans += pow(8, num);
    for (int i = 0; i < num; i++) {
        d *= 8;
        d %= waru;
    }

    ans = a - bc * 2 + d;
    ans %= waru;

    if (ans < 0) ans += waru;

    cout << ans << endl;

    //
}

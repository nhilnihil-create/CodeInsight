#include <bits/stdc++.h>
using namespace std;

long X;

int main(void) {

    cin >> X;

    long a = 100, ans = 0;

    while (a < X) {
        a += a / 100;
        ans++;
    }

    cout << ans << endl;

    return 0;

}
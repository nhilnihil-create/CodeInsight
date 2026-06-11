#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    long long res = 0;
    res += 1000 * (x / 500);
    x %= 500;
    res += 5 * (x / 5);

    cout << res << endl;

    return 0;
}

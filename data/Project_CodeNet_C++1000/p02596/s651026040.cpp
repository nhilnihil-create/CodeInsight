#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin>>k;
    if (k % 7 == 0) k /= 7;
    if (k % 2 == 0 || k % 5 == 0) {
        cout << -1 << '\n';
        return 0;
    }
    if (k == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int a = 1, b = 1;
    while (b > 0) {
        b = 10 * b + 1;
        b %= k;
        a++;
    }
    cout << a << '\n';
    return 0;
}
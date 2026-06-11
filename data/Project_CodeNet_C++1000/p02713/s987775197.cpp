#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    cin >> K;
    int ans = 0;
    for (int a = 1; a < K + 1; a++) {
        for (int b = 1; b < K + 1; b++) {
            for (int c = 1; c < K + 1; c++) {
                ans += __gcd(__gcd(a, b), c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
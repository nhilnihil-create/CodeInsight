#include <bits/stdc++.h>
using namespace std;

int main() {
    int K; cin >> K;
    int ans = 0;
    for (int a = 1; a <= K; a++) {
        for (int b = 1; b <= K; b++) {
            for (int c = 1; c <= K; c++) {
                ans += gcd(gcd(a, b), c);
            }
        }
    }
    cout << ans << endl;
}
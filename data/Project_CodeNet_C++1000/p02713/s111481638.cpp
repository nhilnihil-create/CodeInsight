#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                sum += gcd(i,gcd(j,l));
            }
        }
    }
    cout << sum;
}

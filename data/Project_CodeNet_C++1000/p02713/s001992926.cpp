#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}
int main() {
    int k;
    cin >> k;
    int ans = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                int d = gcd(i, j);
                ans += gcd(d, l);
            }
        }
    }

    cout << ans << endl;
}
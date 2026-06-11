#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long x;
    cin >> x;

    // (A, B) ( -118 <= A <= 119, -119 <= B <= 118 を全探索すればよいことが分かる)
    for (int a = -118; a < 120; a++) {
        for (int b = -119; b < 119; b++) {
            if (pow(a, 5) - pow(b, 5) == x) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}

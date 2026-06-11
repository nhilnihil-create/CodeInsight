#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long a, b, n;
    cin >> a >> b >> n;

    long long x = min(b - 1, n);
    long long f_x = floor(a * x / b) - a * floor(x / b);
    cout << f_x << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

int main() {
    long long a;
    string b;
    cin >> a >> b;

    long long b2 = 100 * (long long)(b[0] - '0') + 10 * (long long)(b[2] - '0') + 1 * (long long)(b[3] - '0');

    long long ans = a * b2 / 100;

    cout << ans << endl;
}

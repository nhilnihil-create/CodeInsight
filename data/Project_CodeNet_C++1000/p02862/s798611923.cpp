#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int a(int A, int B)
{
    if (B == 0)
        return 1;
    if (B % 2 == 1)
        return a(A, B - 1) * A % MOD;
    int C = a(A, B / 2);
    return C * C % MOD;
}
int b(int A, int B)
{
    int C = 1;
    for (int i = A; i <= B; i++)
        C = C * i % MOD;
    return C;
}
signed main()
{
    int x, y;
    cin >> x >> y;

    if ((x + y) % 3)
    {
        cout << 0 << "\n";
        return 0;
    }

    int n = (2 * y - x) / 3, m = (2 * x - y) / 3;
    if (n < 0 || m < 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    cout << b(n + 1, m + n) * a(b(1, m) % MOD, MOD - 2) % MOD << endl;
}
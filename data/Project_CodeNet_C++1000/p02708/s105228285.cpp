#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;
int main(void)
{
    long long n, k; cin >> n >> k;
    long long ans = 0;
    long long l, h;
    for (long long i = k; i <= n + 1; i++)
    {
        l = i * (i - 1) / 2;
        h = n * i - l;
        ans = (ans + h - l + 1) % MOD;
    }
    cout << ans << endl;
}

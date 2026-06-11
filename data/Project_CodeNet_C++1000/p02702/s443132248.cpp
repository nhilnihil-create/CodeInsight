#include <iostream>
#include <cstring>

using namespace std;
char s[2000005];
long long r[2000005], v[2000005];
int main()
{
    cin >> s;
    long long n = strlen(s), p10 = 1, sol = 0;

    for(long long i = n - 1; i >= 0; --i)
    {
        r[i] = r[i + 1] + (s[i] - '0') * p10;
        r[i] %= 2019;
        p10 *= 10;
        p10 %= 2019;
    }

    for(long long i = 0; i <= n; ++i)
    {
        ++v[r[i]];
    }

    for(long long i = 0; i <= 2019; ++i)
    {
        sol += (v[i] - 1) * v[i] / 2;
    }

    cout << sol << '\n';
    return 0;
}

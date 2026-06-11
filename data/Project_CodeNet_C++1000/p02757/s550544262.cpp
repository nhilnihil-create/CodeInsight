#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define lli long long int
#define numberofdigits(x) floor(log10(x)) + 1

lli bin_pow(lli a, lli b)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a;
        b >>= 1;
        a *= a;
    }
    return ret;
}

int main()
{
    lli n, p, d, curr, ans, pow, arr[200005];
    string s;
    cin >> n >> p;
    cin >> s;
    curr = 0, ans = 0;
    memset(arr, 0, sizeof(arr));
    arr[curr]++;
    // pow=1;

    if (p == 2)
    {
        for (lli i = 0; i < n; i++)
        {
            if ((s[i] - '0') % 2 == 0)
                ans += (i + 1);
        }
    }
    else if (p == 5)
    {
        for (lli i = 0; i < n; i++)
        {
            if ((s[i] - '0') % 5 == 0)
                ans += (i + 1);
        }
    }
    else
    {
        lli po = 1;
        for (lli i = n - 1; i >= 0; i--)
        {
            curr = curr + ((s[i] - '0') * po);
            curr = curr % p;
            // if (curr < 0)
            //     curr += p;
            po = (po * 10) % p;
            ans += arr[curr];
            arr[curr]++;
        }
    }
    cout << ans << "\n";
    return 0;
}
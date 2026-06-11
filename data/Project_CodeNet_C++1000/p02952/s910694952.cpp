#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int digit(int n)
{
    int res = 0;
    while (n)
    {
        n /= 10;
        res++;
    }
    return (res);
}

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    rep2(i, 1, n + 1)
    {
        if (digit(i) & 1)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return (0);
}

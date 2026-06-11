#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n;
    cin >> n;

    rep(i, n / 100 + 1)
    {
        int res = n - 100 * i;
        if (0 <= res && res <= 5 * i)
        {
            puts("1");
            return 0;
        }
        if (res < 0)
        {
            break;
        }
    }

    puts("0");
    return 0;
}

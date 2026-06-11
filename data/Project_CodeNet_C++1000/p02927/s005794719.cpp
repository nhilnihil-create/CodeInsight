#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reprev(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
    int m, d, res, d10, d1;
    cin >> m >> d;

    res = 0;
    d10 = d / 10;
    d1 = d % 10;

    rep2(i, 4, m + 1)
    {
        rep2(j, 2, d10 + 1)
        {
            rep2(k, 2, 9+1)
            {
                if (j == d10 && k > d1)
                    break;

                if (i == (j * k))
                    res++;
            }
        }
    }

    cout << res << endl;
}

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

    rep2(i, 1, n+1)
    {
        if ((int)(i * 1.08) == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}
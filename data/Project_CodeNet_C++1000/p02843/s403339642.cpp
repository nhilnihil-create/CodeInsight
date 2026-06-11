#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int x;
    cin >> x;

    int n = x / 100;

    if (100 * n <= x && x <= 105 * n)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }

    return 0;
}

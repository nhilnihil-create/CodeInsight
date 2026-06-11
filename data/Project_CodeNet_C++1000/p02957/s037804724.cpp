#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int a, b;
    cin >> a >> b;

    if (abs(a - b) % 2)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << abs(min(a, b) + abs(a - b) / 2) << '\n';
    }
    return 0;
}

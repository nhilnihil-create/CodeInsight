#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    ll n;
    cin >> n;

    int s = sqrt(n) + 1;
    while (s--)
    {
        if (n % s == 0)
        {
            cout << s + (n / s) - 2 << endl;
            return 0;
        }
    }
}
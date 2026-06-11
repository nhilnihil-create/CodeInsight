#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    rep(i, 9) rep(j, 9)
    {
        if ((i + 1) * (j + 1) == n)
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}
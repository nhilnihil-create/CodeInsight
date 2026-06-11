#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n)
    {
        if (a[i] % 2 == 0)
        {
            if (a[i] % 6 != 0 && a[i] % 10 != 0)
            {
                puts("DENIED");
                return 0;
            }
        }
    }
    puts("APPROVED");
}
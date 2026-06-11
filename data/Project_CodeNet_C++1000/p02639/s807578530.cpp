#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(std::vector<long long> x)
{

    for (ll i = 0; i < 5; i++)
    {
        if (x[i] == 0)
            cout << i + 1 << endl;
    }
}

signed main()
{
    std::vector<long long> x(5);
    for (int i = 0; i < 5; i++)
    {
        scanf("%lld", &x[i]);
    }
    solve(std::move(x));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, cur, res = 0, cur_max = 0;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> cur;
        cur_max = max(cur_max, cur);

        res += cur_max - cur;
    }

    cout << res << "\n";
    return 0;
}

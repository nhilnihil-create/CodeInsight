#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

void rec(int d, ll val, vector<ll> &all)
{
    all.push_back(val);
    if (d == 10)
        return;
    for (int i = -1; i <= 1; i++)
    {
        int add = (val % 10) + i;
        if (add >= 0 && add <= 9)
            rec(d + 1, val * 10 + add, all);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    vector<ll> all;
    for (int v = 1; v < 10; v++)
        rec(1, v, all);

    sort(all.begin(), all.end());
    cout << all[k - 1] << endl;
    return 0;
}

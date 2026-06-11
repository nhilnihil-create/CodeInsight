#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[1000006] = {0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int g = 0, p;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> p;
        ++cnt[p];
        g = __gcd(g, p);
    }
    if (g != 1)
    {
        cout << "not coprime";
        return 0;
    }
    for (int i = 2; i <= 1e6; i++)
    {
        int val = 0;
        for (int j = i; j <= 1e6; j += i)
            val += cnt[j];
        if (val > 1)
        {
            cout << "setwise coprime";
            return 0;
        }
    }
    cout << "pairwise coprime";
}
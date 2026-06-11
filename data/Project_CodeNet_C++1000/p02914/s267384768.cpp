#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n;
long long a[N];

long long base[100];
long long xr, xrs;

void add(long long x)
{
        for (int i = 62; i >= 0; i--)
        {
                if (x & (1LL << i))
                {
                        if (!base[i] && (xrs & (1LL << i)))
                        {
                                base[i] = x;
                                break;
                        }
                        x ^= base[i];
                }
        }
        return;
}

long long Max(long long x)
{
        long long ret = 0;
        long long mask = 0;

        for (int i = 62; i >= 0; i--)
        {
                if (!base[i] || !(x & (1LL << i)) || ret & (1LL << i))
                        continue;
                ret ^= base[i];
        }

        return ret << 1;
}

int main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //freopen("in.in", "r", stdin);

        cin >> n;

        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
                xr ^= a[i];
        }

        long long ans = xr;
        xrs = xr ^ ((1LL << 62) - 1);

        for (int i = 0; i < n; i++)
        {
                a[i] &= xrs;
                add(a[i]);
        }

        long long mxx = Max(xrs);
        cout << mxx + ans;

        return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define sc second
#define int long long
using namespace std;

int n, k;
int a[200000] = {};

int searc(int l, int r)
{
    if (l == r)
        return l;
    int m = (l + r) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (a[i] - 1) / m;
    }
    //cout << " " << l << " " << r << " " << sum << endl;
    if (sum > k)
    {
        return searc(m + 1, r);
    }
    else
    {
        return searc(l, m);
    }
}

int32_t main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << searc(1, 1e9);
}

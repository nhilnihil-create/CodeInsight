#include <bits/stdc++.h>
using namespace std;
int n, m, q, ans = INT_MIN;
vector<int> a, b, c, d;
void check(int i, int num, vector<int> &arr)
{
    if (i == n)
    {
        int sum = 0;
        for (int p = 0; p < q; p++)
        {
            if (arr[b[p]] - arr[a[p]] == c[p])
                sum += d[p];
        }
        ans = max(ans, sum);
        return;
    }
    for (int p = num; p <= m; p++)
    {
        arr[i] = p;
        check(i + 1, p, arr);
    }
}
int main()
{
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    vector<int> arr(n, 0);
    check(0, 1, arr);
    cout << ans;
    return 0;
}
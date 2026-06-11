#include <bits/stdc++.h>
using namespace std;

long long n;
long long ans = 0;
long long a[200010], b[200010];
priority_queue<pair<long long, long long>> q;

int main()
{
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i] < b[i])
        {
            q.push(make_pair(b[i], i));
        }
        else if (a[i] > b[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    while (!q.empty())
    {
        pair<long long, long long> m = q.top(); q.pop();
        long long i = m.second;
        long long pi = i - 1;
        long long ni = i + 1;
        if (pi == -1) pi = n - 1;
        if (ni == n) ni = 0;
        long long x = b[pi] + b[ni];
        long long y = max(b[pi], b[ni]);
        long long cnt = min((b[i] - a[i]) / x, (b[i] - y) / x + 1);
        if (!cnt)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += cnt;
        b[i] -= cnt * x;
        if (b[i] > a[i])
            q.push(make_pair(b[i], i));
    }
    cout << ans << endl;
    return 0;
}
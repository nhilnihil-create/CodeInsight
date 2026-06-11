//#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 100;
const ll mod = 1e9 + 7;
ll ans;
int n;
int a[N],b[N],v[N];
queue <int> q;
int main()
{
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
    for (int i = 0; i < n; ++i)
        if (b[i] >= b[(i + n - 1) % n] + b[(i + 1) % n])
        {
            q.emplace(i);
            v[i] = 1;
        }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        v[x] = 0;
        ll c = (b[x] - a[x]) / (b[(x + n - 1) % n] + b[(x + 1) % n]);
        if (c <= 0 && a[x] != b[x])
        {
            ans = -1;
            break;
        }
        ans += c;
        b[x] -= c * (b[(x + n - 1) % n] + b[(x + 1) % n]);
        int t = (x + n - 1) % n;
        if (!v[t] && b[t] >= b[(t + n - 1) % n] + b[(t + 1) % n])
        {
            v[t] = 1;
            q.emplace(t);
        }
        t = (x + 1) % n;
        if (!v[t] && b[t] >= b[(t + n - 1) % n] + b[(t + 1) % n])
        {
            v[t] = 1;
            q.emplace(t);
        }
    }
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            ans = -1;
    printf("%lld\n", ans);
    return 0;
}
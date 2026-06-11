#include <iostream>

using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
LL du[MAXN], sum[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    // scanf("%d", &n);
    cin >> n;
    LL jian = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        // scanf("%d %d", &u, &v);
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        du[u] += (n - v + 1);
    }
    for (int i = 1; i <= n; i++)
        jian += du[i];
    LL allans = 0;
    for (int i = 1; i <= n; i++)
    {
        allans += (1ll * (n - i + 1) * (n - i + 1 + 1)) / 2;
        allans -= jian;
        jian -= du[i];
    }
    // printf("%lld\n", allans);
    cout << allans << '\n';
    // cin >> n;
    
    
}
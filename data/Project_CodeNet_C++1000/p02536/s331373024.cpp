#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int f[100010];

int find_fa(int x)
{
    if(x != f[x])
        return find_fa(f[x]);
    return x;
}


int main()
{
    ios;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        f[i] = i;
    for(int i = 1; i <= m; ++i)
    {
        int x, y; cin >> x >> y;
        f[find_fa(x)] = find_fa(y);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(f[i] == i)
            ans ++;
    cout << ans-1 << endl;
    return 0;
}

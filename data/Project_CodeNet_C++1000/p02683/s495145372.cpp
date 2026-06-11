#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n, m, x, mn = 1e18, c[15], arr[15][15];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x;
    for(int i = 0;i < n;++i)
    {
        cin >> c[i];
        for(int j = 0;j < m;++j)
            cin >> arr[i][j];
    }
    for(int i = 1;i < (1LL << n);++i)
    {
        ll tmp[m], cost = 0;
        memset(tmp, 0, sizeof tmp);
        for(int j = 0;j < n;++j)
        {
            if(i & (1LL << j))
            {
                cost += c[j];
                for(int k = 0;k < m;++k)
                    tmp[k] += arr[j][k];
            }
        }
        bool valid = 1;
        for(int j = 0;j < m;++j)
            if(tmp[j] < x)
                valid = 0;
        if(valid)   mn = min(mn, cost);
    }
    cout << (mn == 1e18 ? -1 : mn);
    return 0;
}

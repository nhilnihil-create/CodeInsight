#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;
const int MAXN = 1e5+10;
const int NINF = -1e9;
const double eps = 1e-12;

int n, m, v, p;
int a[MAXN];

bool check(int x)
{
    LL sum = a[x]+m;
    if (sum < a[p]) return false;
    LL les = 1LL*m*v;
    les -= 1LL*(p-1)*m;
    les -= 1LL*(n-x+1)*m;
    for (int i = p;i < x;i++)
        les -= min(1LL*m, sum-a[i]);
    return les <= 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    scanf("%d%d%d%d", &n, &m, &v, &p);
    for (int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    sort(a+1, a+1+n, greater<int>());
    int l = p, r = n;
    int ans = p;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if (check(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }
    printf("%d\n", ans);

    return 0;
}

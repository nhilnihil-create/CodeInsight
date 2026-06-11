#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+20;
int n,a[N],c[N],d[N];
long long s1[N],s2[N],f[N];
int main(void)
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]) , c[a[i]]++;
    for (int i=1;i<=n;i++) d[c[i]]++;
    for (int i=1;i<=n;i++)
        s1[i] = s1[i-1] + 1LL * i * d[i],
        s2[i] = s2[i-1] + d[i];
    for (int i=1;i<=n;i++) f[i] = ( s1[i] + ( s2[n] - s2[i] ) * i ) / i;
    for (int k=1;k<=n;k++)
    {
        int l = 1 , r = n;
        while ( l + 1 < r )
        {
            int mid = l + r >> 1;
            k <= f[mid] ? l = mid : r = mid;
        }
        if ( k <= f[r] ) printf("%d\n",r);
        else if ( k <= f[l] ) printf("%d\n",l);
        else puts("0");
    }
    return 0;
}

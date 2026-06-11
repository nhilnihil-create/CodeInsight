#include <bits/stdc++.h>
#define mem(s,t) memset(s,t,sizeof(s))
#define pb(s) push_back(s)
#define inf 0x3f3f3f3f
#define mn 100010
typedef long long ll;
using namespace std;

int a[510][510];

void work(int l,int r,int k)
{
    if (l>=r) return;
    int i,j,mid=(l+r)/2;
    for (i=l;i<=mid;i++)
    for (j=mid+1;j<=r;j++)
        a[i][j]=a[j][i]=k;
    work(l,mid,k+1);
    work(mid+1,r,k+1);
}

int main()
{
    int n,i,j;
    cin>>n;
    work(1,n,1);
    for (i=1;i<n;i++)
    {
        for (j=i+1;j<n;j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][n]);
    }
    return 0;
}


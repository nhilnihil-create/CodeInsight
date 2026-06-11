#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
#include <set>
#include <bitset>
using namespace std;
typedef  long long ll;
const int maxn=1e6+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

ll a[maxn];
ll b[maxn];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        a[i]=a[i-1]+tmp;
    }
    for(int i=1;i<=m;i++)
    {
        int tmp;
        cin>>tmp;
        b[i]=b[i-1]+tmp;
    }
    int ans=0;
    for(int i=0;i<=n&&a[i]<=k;i++)
    {
        int l=0,r=m;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[i]+b[mid]>k) r=mid-1;
            else
            {
                l=mid+1;
                ans=max(ans,i+mid);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

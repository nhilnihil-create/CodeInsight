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
using namespace std;
typedef long long ll;
const int maxn=3e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int a[maxn];
int n,k;

bool jungle(int mid)
{
    if(mid==0) return false;
    int ti=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<mid) continue;
        ti+=a[i]/mid-1;
        if(a[i]%mid>0) ti++;
        if(ti>k) return false;
    }
    return true;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int r=a[n];
    int l=0;
    int mid;
    int ans=0;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(!jungle(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
            ans=mid;
        }
    }
    printf("%d\n",ans);
}

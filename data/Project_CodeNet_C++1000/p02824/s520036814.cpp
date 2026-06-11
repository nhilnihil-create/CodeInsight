#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,v,p,a[N],b[N];
bool judge(int mid)
{
    if(n-mid+1<=p) return true;
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=n;i>=n-p+2;i--) b[i]+=m;
    b[mid]+=m;
    for(int i=mid+1;i<n-p+2;i++)
        if(b[i]>b[mid]) return false;
    int sum=v-p,now=0;
    if(sum<=0) return true;
    for(int i=1;i<n-p+2;i++)
    {
        if(i==m) continue;
        if(b[mid]-b[i]>=m) sum--;
        else
        {
            int x=b[mid]-b[i];
            if(now>=x) now-=x;
            else
            {
                x-=now;now=0;
                if(sum)
                {
                    sum--;now=m-x;
                }
            }
        }
        if(sum==0&&now==0) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&v,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int l=1,r=n,ans;
    while(l<=r)
    {
        int m=l+r>>1;
        if(judge(m)) ans=m,r=m-1;
        else l=m+1;
    }
    printf("%d\n",n-ans+1);
}

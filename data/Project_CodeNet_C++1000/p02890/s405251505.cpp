#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,tot,sum[N],a[N],b[N],ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int t=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) t++;
        else b[++tot]=t,t=1;
    }
    b[++tot]=t;
    sort(b+1,b+1+tot);
    for(int i=1;i<=tot;i++) sum[i]=sum[i-1]+b[i];
    int p=0;
    for(int i=1,j=tot;i<=tot;i++,j--)
    {
        int l=ans[j+1],r=n/j,res;
        while(l<=r)
        {
            int m=l+r>>1;
            int pos=lower_bound(b+1,b+1+tot,m)-b-1;
            if(m*(pos-i+1)-sum[pos]+sum[i-1]<=p)
                res=m,l=m+1;
            else r=m-1;
        }
        ans[j]=res;
        p+=b[i];
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}

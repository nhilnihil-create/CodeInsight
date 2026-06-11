#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int a[300010],num2[300010],num[300010],sum_num[300010],sum_tot[300010];

int check(int m,int n)
{
    int p=0;
    p+= sum_num[n]-sum_num[m-1];
    p+= sum_tot[m-1]/m;
    return p;
}


int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    for(int i=0;i<n;++i) ++num2[a[i]];
    for (int i=0;i<=n;++i) num[ num2[i] ]++;
    sum_num[0]=sum_tot[0]=0;
    for (int i=1;i<=n;++i)
    {
        sum_tot[i]=sum_tot[i-1]+num[i]*i;
        sum_num[i]=sum_num[i-1]+num[i];
    }
    int ll=1;int rr=n;int ans=n;
    for (int k=1;k<=n;++k)
    {
        ll=1;rr=ans;ans=0;
        while (ll<=rr)
        {
            int mid=(ll+rr)/2;
            if ( check(mid,n)>=k ){
                ans=mid;ll=mid+1;
            }
            else rr=mid-1;
        }
        printf("%d\n",ans);
    }

}






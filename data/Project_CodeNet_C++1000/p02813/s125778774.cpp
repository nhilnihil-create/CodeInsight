#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for (int j=0;j<n;j++)
    scanf("%d",&b[j]);
    int fac[9];
    fac[0]=1;
    for (int i=1;i<=8;i++)
    fac[i]=fac[i-1]*i;
    int attend1[9]={};
    int attend2[9]={};
    int val1=0,val2=0;
    for (int i=n-1;i>=0;i--)
    {
        int c1=0,c2=0;
        for (int j=1;j<a[(n-1)-i];j++)
        {
            if (attend1[j]==0)
            c1++;
        }
        for (int j=1;j<b[(n-1)-i];j++)
        {
            if (attend2[j]==0)
            c2++;
        }
        attend1[a[(n-1)-i]]=1;
        attend2[b[(n-1)-i]]=1;
        val1=val1+c1*fac[i];
        val2=val2+c2*fac[i];
    }
    printf("%d\n",abs(val1-val2));
    return 0;
}
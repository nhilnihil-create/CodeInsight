#include <iostream>

using namespace std;
int a[100005];
int gcd(int a,int b)
{
    while(a^=b^=a^=b%=a);
    return b;
}
int main()
{
    int flag=0;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=a[i]/2;
    }
    int res=0;
    long long ans=1;
    for(int i=0;i<n;i++)
    {
        if(i>=2&&(a[i]/gcd(ans,a[i])%2==0||ans/gcd(ans,a[i])%2==0))
        {
            flag=1;
            break;
        }
        ans*=a[i]/gcd(ans,a[i]);
        if(ans>m)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<0;
    else
    {
        long long ens=ans;
        while(ens<=m)
        {
            res++;
            ens+=2*ans;
        }
        cout<<res;
    }
    return 0;
}

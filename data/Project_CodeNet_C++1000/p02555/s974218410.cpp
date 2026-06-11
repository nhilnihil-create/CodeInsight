#include <bits/stdc++.h>
using namespace std;
long long a[2002];
int main()
{
    long long t,i,k,n,x,y=1,z=1,s=1,j;
    cin>>n;

    a[0]=1;
    for(i=3;i<=n;i++)
    {
          for(j=3;j<=i;j++)
          {
              a[i]+=a[i-j];
              a[i]%=1000000007;
          }
    }

    cout<<a[n]<<endl;

    return 0;
}
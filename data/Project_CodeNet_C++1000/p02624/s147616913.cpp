#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,s=0,n;
    cin>>n;
    long long a[n+1];
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j=j+i)
        {
            s=s+j;
        }
    }
    cout<<s;
return 0;}

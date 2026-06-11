#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,s,a[2020],i;
    cin>>s;
    a[0]=a[1]=a[2]=0;a[3]=1;
    for(i=4;i<=s;i++)
    {
        a[i]=(a[i-1]+a[i-3])%1000000007;
    }
    cout<<a[s]<<endl;
    return 0;
}

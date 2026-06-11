#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t,n,a,b,i,j;
    map<ll,ll>m;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            m[i*j]=1;
        }
    }
    cin>>n;
    if(m[n]==1)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}

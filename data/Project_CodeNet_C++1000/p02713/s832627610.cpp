#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,i,j,k,s=0,c=1,x=1,t;
    cin>>n;
    for(i=1;i<=n;i++)
    {
          for(j=1;j<=n;j++)
          {
                    for(k=1;k<=n;k++)
                              s+=__gcd(__gcd(i,j),k);
          }
    }
    cout<<s;
}

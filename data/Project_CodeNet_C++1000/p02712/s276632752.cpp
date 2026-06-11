#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,i,j,k,s=0,c=1,x=1,t;
    cin>>n;
    for(i=0;i<=n;i++)
    {
              if(i%3==0 || i%5==0)
                   continue;
                   else s+=i;
    }
    cout<<s;
}

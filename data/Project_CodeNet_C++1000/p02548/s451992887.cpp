#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll cnt=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(n-(i*j)>0)
                cnt++;
               if(i*j>=n)
                break;
        }
    }
    cout<<cnt<<"\n";
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll k;
    cin>>k;
    ll num=0,ans=-1;
    for(ll i=1;i<=1000009;i++)
    {
        num=10*num+7;
        num%=k;
        if(num==0)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

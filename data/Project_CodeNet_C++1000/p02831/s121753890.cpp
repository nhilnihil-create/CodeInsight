#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll a,b;
    cin>>a>>b;
    ll mn=999999999999999;
    ll ans=a*b;
    for(ll i=2;i<=min(a,b);i++)
    {
        if(ans%i==0 && ((ans/i)%a==0 && (ans/i)%b==0))
            mn=min(mn,(ans/i));
    }
    cout<<min(ans,mn)<<endl;
    return 0;
}

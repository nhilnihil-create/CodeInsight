#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n,ans=0;
    cin>>n;
    if(n%2!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    n/=2;
    while(n>0)
    {
        ans+=(n/5);
        n/=5;
    }
    cout<<ans<<endl;
    return 0;
}

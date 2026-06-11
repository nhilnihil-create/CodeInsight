#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
#define r  1000001
int main()
{
    ll n;
    cin>>n;

    ll mini=n-1;

    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll d=n/i;
            mini=min(mini,i+d-2);
        }
    }
    cout<<mini<<"\n";
    return 0;
}

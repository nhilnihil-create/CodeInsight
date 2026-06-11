#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,coun=0;
    cin>>n;
    ll sum=n+100;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            coun++;
            ll x= n/i;
            if(i+x<sum)sum=(i+x);

        }
    }
    if(coun==0)
        cout<<n-1<<endl;
    else{
       cout<<sum-2<<endl;
    }
}

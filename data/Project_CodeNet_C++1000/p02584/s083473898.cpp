#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll x,k,d;
    cin>>x>>k>>d;
    if(x<0) x*=-1;
    ll kp=(x/d);
    ll ans;
    if(kp>=k)
        ans=x-(d*k);
    else
    {
        ll p1=x-(d*kp);
        ll p2=d-p1;
        k=k-kp;
        if(k%2==0)
            ans=p1;
        else
            ans=p2;
    }
    cout<<ans<<endl;
    return 0;
}

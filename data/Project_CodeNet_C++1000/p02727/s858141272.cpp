

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
{
    priority_queue<ll>xa;
    priority_queue<ll>yb;
    priority_queue<ll>cc;
    ll x, y, a, b, c;
    cin>>x>>y>>a>>b>>c;
    ll val;
    for(int i=0;i<a;i++)
    {
        cin>>val;
        xa.push(val);
    }
    for(int i=0;i<b;i++)
    {
        cin>>val;
        yb.push(val);
    }
    for(int i=0;i<c;i++)
    {
        cin>>val;
        cc.push(val);
    }
    ll ans=0;
    ll n=x+y;
    while(x--)
    {
        cc.push(xa.top());
        xa.pop();
    }
    while(y--)
    {
       cc.push(yb.top());
       yb.pop();
    }
    while(n--)
    {
        ans+=cc.top();
        cc.pop();
    }
    cout<<ans<<endl;

    return 0;
}
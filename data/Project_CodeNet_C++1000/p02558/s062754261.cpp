#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[200005];
ll _root(ll x)
{
    while(a[x]!=x)
    x=a[x];
    return x;
}
void add(ll x,ll y)
{
    ll xx=_root(x);
    ll yy=_root(y);
    a[yy]=xx;
}
int main() {
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    a[i]=i;
    ll q;
    cin>>q;
    while(q--)
    {
        ll t;
        cin>>t;
        ll x,y;
        cin>>x>>y;
        if(t==0)
        {
        if(_root(x)!=_root(y))
        {
            add(x,y);
        }
        }
        else
        {
            if(_root(x)==_root(y))
            cout<<1<<endl;
            else
            cout<<0<<endl;
        }
    }

}

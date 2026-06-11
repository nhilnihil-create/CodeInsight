#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[500005];
ll bit[500005];
ll n;
void update(ll i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=(i&(-i));
    }
}
ll query(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i=i-(i&(-i));
    }
    return s;
}
int main() {
    //ll n;
    cin>>n;
    ll q;
    cin>>q;
    for(ll i=1;i<=n;i++)
    cin>>a[i];
    
    for(ll i=1;i<=n;i++)
    update(i,a[i]);
    while(q--)
    {
        ll z,x,y;
        cin>>z>>x>>y;
        x++,y++;
        if(z==1)
        {
            cout<<query(y-1)-query(x-1)<<endl;
        }
        else
        {
            a[x]+=(y-1);
            update(x,y-1);
        }
    }
}
    
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll a[500005];
ll bit[500005];
void fill(ll i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        //cout<<i<<" "<<(i&(-i))<<endl;
        i+=i&(-i);
        
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
int main()
{
    ll q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(ll i=1;i<=n;i++)
    fill(i,a[i]);
    while(q--)
    {
        ll x,l,r;
        cin>>x>>l>>r;
        l++;r++;
        if(x==0)
        {
            fill(l,r-1);
        }
        else
        {
            cout<<query(r-1)-query(l-1)<<endl;
        }
    }
    
    
}
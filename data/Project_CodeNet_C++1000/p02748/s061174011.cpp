#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll a,b,m;
    cin>>a>>b>>m;
    ll arr[a+5]= {0};
    ll brr[b+5]= {0};
    ll mna=INT_MAX;
    ll mnb=INT_MAX;
    for(int i=0; i<a; i++)
    {
        cin>>arr[i];
        mna=min(mna,arr[i]);
    }
    for(int i=0; i<b; i++)
    {
        cin>>brr[i];
        mnb=min(mnb,brr[i]);
    }
    ll sum=mna+mnb;
    ll arek=INT_MAX;
    for(int i=0;i<m;i++)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        ll f=arr[x-1];
        ll ff=brr[y-1];
        ll tot=f+ff-c;
        arek=min(tot,arek);

    }
    cout<<min(arek,sum)<<endl;


}

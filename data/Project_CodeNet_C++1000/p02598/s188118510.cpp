#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
    ll n,p,q,x,y,i,k,a,b;

    cin>>n>>k;
    ll ara[n];
    for(i=0;i<n;i++) cin>>ara[i];

    if(k==0){
        cout<<*max_element(ara,ara+n)<<endl;
        return 0;
    }

    ll mx= 1e18+100;

    ll l=1, r=mx;
    bool bl=false;

    while(l<=r){
        ll mid=(l+r)/2ll;
        ll tot=0;

        for(i=0;i<n;i++){
            ll x=(ara[i]-1)/mid;
            tot+=x;
        }


        if(tot<=k) mx=min(mx, mid), r=mid-1;
        else l=mid+1;

    }

    cout<<mx<<'\n';
}

#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i],sum+=a[i];
    sort(a.rbegin(),a.rend());
    ll k=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=(1.0*sum/(4*m)))k++;
    }
    if(k>=m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++)
    cin>>a[i]>>b[i];
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    if(n%2==1)
    {
        cout<<abs(a[n/2]-b[n/2])+1<<endl;
    }
    else
    {
        ll p=abs(a[n/2]+a[n/2-1]-b[n/2-1]-b[n/2]);
        cout<<p+1<<endl;
    }
    
}
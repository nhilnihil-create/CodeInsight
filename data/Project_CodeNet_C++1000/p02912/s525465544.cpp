/*
hey stop, don't skip the shit till it's solved
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll n,m;
cin>>n>>m;
ll a;
priority_queue<ll> pq;
ll ans=0;
for(ll i=0;i<n;i++)
{
cin>>a;
ans+=a;
pq.push(a);
}
for(ll i=0;i<m;i++)
{
ll k=pq.top();
k/=2;
ans-=(pq.top()-k);
pq.pop();
pq.push(k);
}
cout<<ans<<endl;
}
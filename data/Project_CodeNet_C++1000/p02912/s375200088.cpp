#include <bits/stdc++.h>
#define ll long long int
#define s second
#define f first
#define pb push_back
#define mk make_pair
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    ll sum=0;
    priority_queue<pair<ll,ll>> pq;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    for(ll i=0;i<n;i++)
    {
        pq.push({arr[i]-arr[i]/2,arr[i]});
    }
    ll dif=0;
    while(m--)
    {
        auto it=pq.top();
        ll x=it.f;
        ll y=it.s;
        dif+=x;
        pq.pop();
        y/=2;
        pq.push({y-y/2,y});
    }
    cout<<sum-dif<<endl;
}
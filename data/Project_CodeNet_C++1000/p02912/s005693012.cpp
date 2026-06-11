#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define in insert
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll a[n];
    priority_queue<int>q;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        q.push(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        ll x=q.top();
        q.pop();
        x/=2;
        q.push(x);
    }
    ll sum=0;
    while(q.size())
    {
        sum+=q.top();
        q.pop();
    }
    cout<<sum;
    return 0;
}
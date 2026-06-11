#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> pre(n);
    vector<ll> pos(n+1);
    pos[n] = 0;
    pre[0] = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i>0)
            pre[i] = pre[i-1]^a[i-1];
    }
    pos[n-1] = a[n-1];
    for(int i=n-1; i>=0; i--)
        pos[i] = pos[i+1]^a[i];
    for(int i=0; i<n; i++)
    {
        cout<<(pre[i]^pos[i+1])<<" ";
    }
    return 0;
}
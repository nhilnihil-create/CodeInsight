#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll i,j,k,n,c=0;
    vector<ll> v;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {ll q; cin>>q; v.push_back(q);}
    if(k>=n)
    {
        cout<<0;
    }
    else
    {
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(i=k;i<n;i++)
        {
            c=c+v[i];
        }
        cout<<c;
    }
    return 0;
}
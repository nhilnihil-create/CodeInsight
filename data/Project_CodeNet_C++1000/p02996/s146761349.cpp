#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool compare( pair<ll,ll> a ,pair<ll,ll> b )
{
    if( a.second == b.second )
        return a.first < b.first ;
    return a.second < b.second;
}
int main()
{
    ll n;
    cin>>n;
    auto* a = new pair<ll,ll>[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first >>a[i].second;
    }
    sort( a , a+n , compare );
    ll curr =0;
    bool ans = true;
    for( int i=0;i<n;i++)
    {
        if( curr + a[i].first > a[i].second )
        {
            ans = false;
            break;
        }
        curr = curr + a[i].first;
    }
    if( ans )
    {
        cout<<"Yes";
    }
    else cout<<"No";
}
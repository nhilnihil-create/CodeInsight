#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
#define vl vector<ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 100005


int main()
{
    ll l,r;cin>>l>>r;
    if((r-l)>=2019)
    cout<<"0"<<"\n";
    else
    {
        ll mn=INT_MAX;
        for(ll i=l;i<r;i++)
        {
            for(ll j=i+1;j<=r;j++)
            {
                ll x=i*j;
                mn=min(mn,x%2019);
            }
        }
        cout<<mn<<"\n";
    }
}   
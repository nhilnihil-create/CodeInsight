#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define mod 1000000007


int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    ll p=0;
    for(ll i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            p=1;break;
        }
    }
    if(p)
    cout<<"NO"<<"\n";
    else
    cout<<"YES"<<"\n";
}
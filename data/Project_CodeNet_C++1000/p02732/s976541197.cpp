#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define pi  3.14159265359
#define mod 1000000007
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n;
    cin>>n;
    map<ll,ll>val;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        val[a[i]]++;
    }
    ll total=0;
    for(auto it=val.begin();it!=val.end();it++)
    {
        total+=(it->second*(it->second-1));
    }
    for(int i=0;i<n;i++)
    {
        ll ans=total;
        ans=ans-(val[a[i]]*(val[a[i]]-1));
        ll cal=val[a[i]]-1;
        ans+=(cal*(cal-1));
        cout<<ans/2<<endl;
    }



}


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define sll set<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define endl "\n"
const ll maxn = 2e5+2;
ll flag[1000002];

int main()
{
    fastio;
    ll i, j, k, n, m, t;
    vll a;
    memset(flag,0,sizeof(flag));

    cin>>n;
    for ( i = 0; i < n; i++)
    {
        cin>>j;
        a.pb(j);
    }
    sort(all(a));
    for ( i = 0; i < n-1; i++)
    {
        if(a[i]==a[i+1])    
            flag[a[i]]=1;
    }
    
    ll maxi=*max_element(all(a));

    for ( i = 0; i < n; i++)
    {
        for ( j = 2*a[i]; j<= maxi ; j+=a[i])
        {
            flag[j]=1;
        }
    }
    ll c=0;
    a.clear();
    for ( i = 0; i < n; i++)
    {
        if(flag[a[i]]==0)
            c++;
    }
    cout<<c<<endl;

        
    return 0;
}
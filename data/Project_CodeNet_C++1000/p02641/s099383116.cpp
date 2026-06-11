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

int main()
{
    fastio;
    ll i, j, k, n, m, t;
    ll x;
    ll flag[maxn];
    memset(flag,0,sizeof(flag));

    cin>>x>>n;
    for ( i = 0; i < n; i++)
    {
        cin>>j;
        flag[j]=1;
    }

    j=1;
    if(flag[x]==0)
    {
        cout<<x<<endl;
        return 0;
    }

    while (1)
    {
        if(flag[x-j]==0)
        {
            cout<<x-j<<endl;
            break;
        }
        if(flag[x+j]==0)
        {
            cout<<x+j<<endl;
            break;
        }
        j++;
    }
    

        
    return 0;
}
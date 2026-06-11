#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define forn(i,n1, n2) for (ll i = n1; i < n2; i++)
#define w(t) ll t;cin>>t;while(t--)
#define en "\n"
#define f first
#define s second
const ll mod = 1000000007;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,d,x,y,ans=0;
    cin>>n>>d;
    while(n--)
    {
        cin>>x>>y;
        if(x*x+y*y<=d*d)
        ans++;
    }
    cout<<ans;
    return 0;
}
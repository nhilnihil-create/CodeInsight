//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debug cout<<"debugged\n";
#define minval -2e9
#define maxval 1e9
long double PI =3.14159265358979323846;
 
const ll M=1e12;
const ll inf=1e18;
const ll ms=10000000;
fast;
ll ans,n,m;
void solve()
{
    cin>>n;ll ar[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    for(int i=2;i<n;i++)
    {
        if(ar[i-1]<ar[i]&&ar[i]<ar[i+1])
            ans++;
        else if(ar[i-1]>ar[i]&&ar[i]>ar[i+1])
            ans++;
    }
   cout<<ans<<endl;
    
}
int main()
{
    solve();
    return 0;
}
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
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
double ans;
ll n,m,q;
void solve()
{
    cin>>m;
    for(ll i=1;i<=m;i++)
    {
        double a;cin>>a;
        ans+=1/a;
    }
    cout<<1/ans<<endl;
}   

int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
   // int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}

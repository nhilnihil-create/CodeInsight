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
    cin>>n>>m;
    m=2*m+1;
    cout<<ceil(1.0*n/m)<<endl;
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}

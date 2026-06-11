#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238463;
const int MAXN = 200005;
int main()
{
    FAST
    ll a;
    ld b;
    cin>>a>>b;
    ll temp=b*100+0.5;
    ll ans=temp*a;
    ans/=100;

    cout<<fixed<<setprecision(0)<<ans<<endl;
    return 0;
}

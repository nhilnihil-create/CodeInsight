/*Learning is endless*/
#include <bits/stdc++.h>
#define endl "\n";
#define pii pair<int,int>;
using namespace std;
typedef long long ll;
const ll BIG=1000000007;
const double PI=3.141592653589793238;
template <typename T,typename Q>
T max(T a,Q b)
{
    if(a<b)
        return b;
    return a;
}
template <typename T,typename Q>
T min(T a,Q b)
{
    if(a>b)
        return b;
    return a;
}
long gcd(long a,long b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=max(max(max(a*c,a*d),b*c),b*d);
    cout<<ans;
}
int main() {
    int t;
  	t=1;
    while(t--)
        solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const long long int infLL = 9000000000000000000;
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(a) (a).begin(),(a).end()
#define mx_int_prime 999999937
const int inf = 2000000000;
const double PI = acos(-1);
const double eps = 1e-9;
typedef long double ld;
#define MOD 1000000007
const unsigned int M = 1000000007;
typedef long long ll;
const int mx=2e5+125;
int ar[mx],br[mx],pos[mx];
#define PB push_back
#define endl '\n'
#define S second
#define F first
void solve()
{

    ll n;
    cin>>n;
    ll ans=(n*(n+1))/2;
    cout<<ans-n<<endl;


}
int main()
{
    faster();
    int tc;
    tc=1;
    while(tc--)
        solve();
    return 0;
}


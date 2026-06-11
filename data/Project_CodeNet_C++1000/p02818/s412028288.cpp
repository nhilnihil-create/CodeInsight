/*input
500000000000 500000000000 1000000000000

*/
#include<bits/stdc++.h>
#define ull         unsigned long long
#define ll             long long
#define M             1000000007
#define pb             push_back
#define p_q         priority_queue
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll)x.size()    
#define endl        '\n'
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp             make_pair
#define lb             lower_bound
#define ub            upper_bound
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ini(a,n,b)    for(ll int i=0;i<n;i++) a[i]=0;
#define F            first
#define S            second
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define TIME        cerr << "\nTime elapsed: " << setprecision(5) <<1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

bool DEBUG = 0;

void solve()
{
    //initialize();
    ll a,b,k;cin>>a>>b>>k;
    if (k <= a)
    {
        cout<<(a-k)<<" "<<b<<"\n";
    }
    else if (k <= (a+b))
    {
        cout<<0<<" "<<(a+b - k)<<"\n";
    }
    else
    {
        cout<<0<<" "<<0<<"\n";
    }
}


int main(void)
{
    ios
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
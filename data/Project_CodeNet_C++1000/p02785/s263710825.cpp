#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int mx=1e6+11;
const double PI = acos(-1);
#define MOD 1000000007


#define nl '\n'
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair

#define sz(x) x.size()
#define sa(v) sort(v.begin(),v.end())
#define sd(v) sort(v.begin(),v.end(),greater<>())
#define rev(s) reverse(s.begin(),s.end())
#define tt int t; cin>>t; while(t--)
#define lo(i,a,b) for(ll i=a;i<b;i++)
#define be(a) (a).begin(),(a).end()
#define rbe(a) (a).rbegin(),(a).rend()

#define sqr(a) ((a) * (a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define mem(a,b) memset(a,b,sizeof(a))

#define yes cout<<"YES"<<nl;
#define no cout<<"NO"<<nl;

#define su ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define frac cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree< long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
void erase ( ordered_set &s, long long val )
{
    auto it = s.upper_bound(val);

    if ( it == s.begin() && val == *s.begin() ) s.erase ( s.upper_bound(val) );
    else s.erase ( s.upper_bound(val) );
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}


int main()
{
   su;
   int n,k;
   cin>>n>>k;
   ll a[n],sum=0;
   lo(i,0,n)
   {
     cin>>a[i];
   }
   sort(a,a+n);
   lo(i,0,n-k)
   {
     sum+=a[i];
   }
   cout<<sum<<nl;
   return 0;
}

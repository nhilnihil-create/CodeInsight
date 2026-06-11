#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORX(i, a, b, x) for (int i = (a); i <= (b); i+=x)
#define debug(x) cerr << #x << " is= " << x << endl; //use for debugging
#define read(a) int a; cin >> a;
#define reads(s) string s; cin >> s;
#define readb(a, b) int a, b; cin >> a >> b;
#define readc(a, b, c) int a, b, c; cin >> a >> b >> c;
#define readarr(a, n) int a[(n) + 5] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define readmat(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
 
#define printarr(a, n) FOR (i, 1, n) cout << a[i] << " "; cout << endl;
#define printv(v) for (int i: v) cout << i << " "; cout << endl;
#define printmat(a, n, m) FOR (i, 1, n) {FOR (j, 1, m) cout << a[i][j] << " "; cout << endl;}
 
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define mp(a,b) make_pair(a,b)
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long int
#define vi         vector<int>
#define vll        vector<ll>
#define vpii       vector<pair<int,int>>
#define vov        vector<vector<int>> 
#define pr         pair<ll,ll>
#define vpll       vector<pair<ll,ll>>
#define all(v)     v.begin(),v.end()
#define rall(v)    v.rbegin(),v.rend()  //reverse of above;
#define sz(container) int((container).size())
#define cut(x) {cout<<x<<"\n"; return 0;}
#define setprec(x) cout << fixed << showpoint << setprecision(8)<<x<<endl;
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define time cout << clock() / double(CLOCKS_PER_SEC) << endl;
#define endl "\n"
#define mod 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//*s.find_by_order() ->returns an iterator to the k-th largest element (counting from zero);
//s.order_of_key() ->number of elements strictly smaller then our item;
//st.rbegin()->second; last element in set
//st.erase(prev(st.end())); delete last element in set;
//sort(a+1,a+n+1,[](ll x,ll y){return abs(x)>abs(y);});
//sort(v.begin(), v.end(), greater<int>()); 
const int N=3e5+5;
ll n,a[N][65],ans=0,p=0,x,y,b[N];
ll powm(ll a,ll b)
{
    ll r=a%mod,ans=1;
    while(b>0)
    {
        if(b%2==1)
        ans=(ans*r)%mod;
        r=(r*r)%mod;
        b>>=1;
    }
    return ans;
}
void solve()
{
 //n*662;
 FOR(i,1,n)
 {
  FOR(j,0,62)
  if(b[i]&(1ll<<j)) a[i][j]=1;
 }
 //n*662;
 FOR(j,0,62)
 {
  FOR(i,1,n)
  a[i][j]=a[i][j]+a[i-1][j];
 }
 //n*662;
 FOR(i,1,n-1) // iterate for each row;
 {
    //cout<<"for i= "<<i<<endl;
    FOR(j,0,62)
 {
   x=a[n][j]-a[i][j];
   y=n-i-x;
   //cout<<"for j= "<<j<<endl;
   //cout<<"x= "<<x<<" y= "<<y<<endl;
   if(b[i]&(1ll<<j)) ans+=((powm(2,j)*y))%mod;
   else ans+=((powm(2,j)*x))%mod;
   ans%=mod;
   //cout<<"ans= "<<ans<<endl;
 }
 }
 cout<<ans;
}
int main()
{
  fast_io;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  cin>>n;
  FOR(i,1,n) cin>>b[i];
  solve();
}

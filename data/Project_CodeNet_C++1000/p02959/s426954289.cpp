//nani?
#include<bits/stdc++.h>
#define pi acos(-1);
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define f(i,a,b) for( int i = a; i < b ; i++ )
#define sor(a) sort( a.begin(), a.end() )
#define rsor(a) sort( a.rbegin(), a.rend() )
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
//#define inf 1LL<<62
typedef long long ll;
typedef double ld;
using namespace std;
const ll inf=1e10+6;
const ll MOD=1e9+7;
const ll mod=998244353;
// ac cmtr;
const int MAX_N = 1e6+5;
const int LG = 25;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);}
#else
#define trace(...)
#endif
//---------------------------

ll a[MAX_N];
ll  b[MAX_N];

int main(){
    fastio;
    ll n;
    cin>>n;
    f(i,0,n+1) cin>>a[i];
    f(i,0,n) cin>>b[i];
    ll ans = 0;
    f(i,0,n){
        if(a[i] > b[i]) ans+=b[i];
        else if(a[i+1] + a[i]> b[i]) {ans+=b[i];a[i+1] = a[i+1]+a[i] -b[i];}
        else {ans+=(a[i+1]+a[i]);a[i+1] = 0;}
    }
    cout<<ans<<endl;

}





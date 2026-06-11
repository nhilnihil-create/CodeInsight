#include <bits/stdc++.h>
 
#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ones(x) (ll) __builtin_popcount(x)
#define fs first
#define sc second
#define pb push_back
#define po pop_back
#define mp make_pair  
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tsie(nullptr);cout.tie(nullptr)
 #define watch(x) cout<<(#x)<<" is " <<x<<"\n"

#define PI 3.1415926535
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
const ll mod = 1e9 + 7;
const ll MAX = 3e3+7;
const ll inf = 1e18+1;
ll a[MAX],b[MAX],dp[MAX][4];
int main(){
 fastio;
 ll n,t;
 cin>>n>>t;

 f(i,0,n){
    cin>>a[i]>>b[i];
 }

 f(i,0,n){
    af(j,t,0){
        if(t>a[i]+j){
        dp[j+a[i]][0] = max(dp[j+a[i]][0],dp[j][0] + b[i]);
        dp[j+a[i]][1] = max(dp[j+a[i]][1],dp[j][1] + b[i]);
        }
        dp[j][1] = max(dp[j][1],dp[j][0]+b[i]);
    }
 }
 cout<<dp[t-1][1]<<"\n";
 return 0; 
}
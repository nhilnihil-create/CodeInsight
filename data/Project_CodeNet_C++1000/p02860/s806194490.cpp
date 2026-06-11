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
const ll MAX = 1e5+7;
const ll inf = 1e18+1;


int main(){
 fastio;
 ll n;
 cin>>n;
 string s;
 cin>>s;
 bool go =true;
 if(n&1) {cout<<"No\n";return 0;}
 f(i,0,n/2){
    if(s[i]!=s[i+n/2]) go = false;
 }
 if(go) cout<<"Yes\n";
 else cout<<"No\n";
 return 0; 
}
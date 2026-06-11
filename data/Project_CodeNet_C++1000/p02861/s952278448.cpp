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
ld dist[10][10];
int main(){
 fastio;
 ll n;
 cin>>n;
 vii v;
 vi p;
 f(i,0,n){
    ll a,b;
    cin>>a>>b;
    v.pb({a,b});
 }
 f(i,0,n) {
        f(j,0,n) {
            dist[i][j] = powl((v[i].fs-v[j].fs)*(v[i].fs-v[j].fs)+(v[i].sc-v[j].sc)*(v[i].sc-v[j].sc), (ld) 0.5);
        }
    }
f(i,0,n) p.pb(i);
 ld prom = 0,cont=0;
 do { 
    ld dis=0;
    f(i,0,n-1){
        dis += dist[p[i]][p[i+1]];
    }   
    prom+=dis;
    cont++;
    } while (next_permutation(all(p))); 
 cout<<setprecision(20)<<prom/cont<<"\n";
 return 0; 
}
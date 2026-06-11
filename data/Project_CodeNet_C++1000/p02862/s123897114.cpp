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
const ll MAX = 1e6+7;
const ll inf = 1e18+1;

ll binpow(ll a,ll b,ll m){
    a%=m;
    ll res =1;
    while(b>0){
        if(b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
ll fact[MAX+5];
ll invmod(ll n){
    return binpow(n,mod-2,mod);
}
ll combi(ll n ,ll k){
    ll arriba = fact[n]%mod;
    ll abajo = (fact[n-k]*fact[k])%mod;
    return (arriba*invmod(abajo))%mod;
}
void factpre(){
    fact[0]=1;
    f(i,1,MAX){
        fact[i]=(i*fact[i-1])%mod;
    }
}
int main(){
 fastio;
 factpre();
 ll x,y,aux;
 cin>>x>>y;
 if((x+y)%3!=0){cout<<"0\n";return 0;}
 aux =(x+y)/3;
 if(2*min(x,y)<max(x,y)){cout<<"0\n";return 0;}
 x-=aux,y-=aux;
 ll a = x+y;
 cout<<combi(a,x)<<"\n";
 return 0; 
}
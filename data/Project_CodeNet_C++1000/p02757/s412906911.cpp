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
#define watch(x) cout << (#x) << " is " << (x) <<"#" <<endl
#define PI 3.1415926535
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> ii ;
typedef vector<ll>  vi ;
typedef vector<ii> vii ;
const ll mod = 998244353;
const ll MAX = 3e3+23;
const ll inf = 1e18+7;

ll binpow(ll a, ll b, ll m){
    ll res = 1;
    while(b>0){
        if(b%2==1){
            res = (res*a)%m;
        }
    a = (a*a)%m;
    b/=2;
}   
    return res;
}
ll combi(ll a){
    return a*(a-1)/2;
}
ll cnt[10030];
int main(){
  fastio;
  ll n,p;
  cin>>n>>p;
  string s;
  cin>>s;
  if(p==5 || p==2){
    ll ans=0;
    f(i,0,n){
        if((s[i]-'0')%p==0)ans+=i+1;
    }
    cout<<ans<<"\n";
    return 0;
  }
  cnt[0]=1;
  ll aux =0,ans=0;
  f(i,0,n){
    aux*=10;
    aux+=s[i]-'0';
    aux%=p;
    ans = binpow(10,n-1-i,p)*aux;
    ans%=p;
    cnt[ans]++;
  }
  ans =0;
  f(i,0,p) ans+=combi(cnt[i]);
  cout<<ans<<"\n";
  return 0; 
}
//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pi;
typedef vector<pair<ll, ll>> vpi;
 
//const long long INF = 1LL << 55;
 
#define itn ll
#define endl '\n'
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(ll i = 0;i < n;i++)
#define rep(i,n) for(ll i = 0;i < n;i++)
#define rrep(i,n) for(ll i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define ioboost cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20)
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, ll mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

ll n;
ll cnt[300030];
ll D[300030];
int main(void){
   ioboost;
   cin >> n;
   rep(i,n){
      ll a;cin >> a;
      cnt[a]++;
   }
   rep(i,300030){
      D[cnt[i]]++;
   }
   
   vector<ll> k_d(300010,0);
   vector<ll> d_c(300010,0);
   
   rep(i,300010){
      k_d[i+1] = k_d[i] + i * D[i];
      d_c[i+1] = d_c[i] + D[i];
   }
   
   vector<ll> F(300012,0);
   
   rep(X,300010){
      if(!X)continue;
      ll bunbo = 0;
      bunbo += k_d[X+1] + X * (d_c[n+1] - d_c[X+1]);
      F[X] = bunbo / X;
   }
   
  // for(int i = 0;i < 100;i++) cout << F[i] << endl;
  F[0] = LONG_MAX;
  int m;
  rep(i,300010){
      if(!F[i]){m = i;break;}
  }
  F.resize(m+1);
  //for(auto i : F)cout << i << endl;
  reverse(all(F));
  for(ll k = 1;k <= n;k++){
      auto idx = lower_bound(all(F),k);
      cout << m - (idx - F.begin()) << endl;
  }
  
}
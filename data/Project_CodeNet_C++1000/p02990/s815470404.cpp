#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define EPS (1e-9)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

const string YES = "";
const string NO  = "";

typedef long long ll;

const ll mod = 1000000007LL;

long long extgcd(long long a,long long b,long long& x,long long& y)
{
  long long d = a;
  if(b != 0){
    d = extgcd(b,a%b,y,x);
    y -= (a/b)*x;
  }
  else
    x = 1,y = 0;
  return d;
}

long long mod_inv(long long a,long long m)
{
  long long x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}


const int MAXnCk = 400001;
ll fact[MAXnCk+1], fact_inv[MAXnCk+1];
void init_nCk(){
  fact[0] = fact_inv[0] = 1;
  REP(i,1,MAXnCk+1) {
    fact[i] = fact[i-1] * (ll)i % mod;
    fact_inv[i] = mod_inv(fact[i],mod);
  }
}

ll nCk(ll n,ll k){
  if( n < 0 || k < 0 || k > n ) return 0LL;
  if( n-k < k ) k = n-k;
  return fact_inv[k] * fact[n] % mod * fact_inv[n-k] % mod;
}


void solve() {

}

int main() {
  init_nCk();
  ll N, K;
  cin >> N >> K;
  ll B = K;
  ll R = N - K;
  REP(i,1,K+1) {
    ll rem_B = B - i;
    ll rem_R = R - ( i - 1 );
    ll ans = ( nCk(rem_B+i-1,rem_B) * nCk(i+rem_R,rem_R) ) % mod;
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

ll kazu[100010];
const long long mod = 998244353;
long long modpow(long long a, long long n) {
  long long atai = 1;
  while (n > 0) {
    if (n % 2) {
      atai *= a;
	  atai%=mod;
      n-=1;
    } 
    a *= a;
    a%=mod;
    n /= 2;
  }
  return atai;
}
int main(){
  int n;
  cin>>n;
  vector<ll>d(n);
  ll saidai=0;
  rep(i,n){
    cin>>d[i];
    if(i!=0)kazu[d[i]]++;
    if(i!=0&&d[i]==0||d[0]!=0){
      cout<<0<<endl;
      return 0;
    }
    chmax(saidai,d[i]);
  }
  ll ans=1;
  for(int i=2;i<=saidai;i++){
      ans*=modpow(kazu[i-1],kazu[i]);
      ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}
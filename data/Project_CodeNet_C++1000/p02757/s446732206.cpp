#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define lb(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define ub(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
const ll mod=1000000007;
//const ll mod=998244353;
const ld pi=acos(-1.0);
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,p;
  string s;
  cin>>n>>p>>s;

  ll ans=0;

  if(p==2){
    rep(i,n){
      if((s[i]-'0')%2==0) ans+=i+1;
    }
    cout << ans << endl;
    return 0;
  }
  if(p==5){
    rep(i,n){
      if((s[i]-'0')%5==0) ans+=i+1;
    }
    cout << ans << endl;
    return 0;
  }

  vector<ll> q(p);
  q[0]=1;
  ll now=0;
  ll ju=1;
  for(int i=n-1;i>=0;i--){
    now+=((s[i]-'0')*ju);
    now%=p;
    q[now]++;
    ju=(ju*10)%p;
  }

  rep(i,p){
    ans+=q[i]*(q[i]-1)/2;
  }

  cout << ans << endl;
}

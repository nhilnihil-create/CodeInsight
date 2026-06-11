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
using Pair = pair<ll,pair<int,int>>;
#define pq priority_queue<Pair, vector<Pair>, greater<Pair>> 
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
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる
 
 
 
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  ll n,d,a;
  cin>>n>>d>>a;
 
  map<ll,ll> mon;
  set<ll> za;
  rep(i,n){
    ll x,h;
    cin>>x>>h;
    ll kai=(h+a-1)/a;
    mon[x]=kai;
    za.insert(x);
    za.insert(x+2*d+1);
  }
 
  vector<ll> ba;
  for(auto z : za){
    ba.pb(z);
  }
  
  sort(all(ba));
 
  map<ll,ll> gen;
 
  ll ans=0;
  ll now=0;
  rep(i,ba.size()){
    if(gen.count(ba[i])) {
      now-=gen.at(ba[i]);
    }
    if(mon.count(ba[i])) {
      ll bom=max(0ll,mon.at(ba[i])-now);
      ans+=bom;
      gen[ba[i]+2*d+1]=bom;
      now+=bom;
    }
  }
 
  cout << ans << endl;
}
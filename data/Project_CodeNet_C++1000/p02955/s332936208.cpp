#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
using ld=long double;
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rRep(i,a,b) for(int i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
ll gcd(ll a,ll b){return (b == 0 ? a : gcd(b, a%b));}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll MOD=1000000007;
constexpr ll INF=1000000011;
constexpr ll MOD2=998244353;
constexpr ll LINF = 1001002003004005006ll;
constexpr ld EPS=10e-8;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}
template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}
template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v){
  for(auto i=begin(v); i != end(v); ++i){
    if(i !=begin(v)) os << ' ';
    os << *i;
  }
  return os;
}

ll N,P,A[507],sum=0;

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

bool check(ll X){
  ll mas = 0;
  pair<ll,ll> C[507];
  ll D[507],E[507];
  rep(i,N){
    C[i].fr=A[i]%X;
    C[i].sc=(C[i].fr == 0LL ? 0LL :X-C[i].fr);
  }
  sort(C,C+N);
  D[0]=0;
  E[N]=0;
  ll K=0;
  rep(i,N){
    K+=C[i].fr;
    D[i+1]=K;
  }
  K=0;
  rRep(i,N-1,0){
    K+=C[i].sc;
    E[i]=K;
  }
  rep(i,N+1){
    if(D[i]==E[i]){
      mas = D[i];
      break;
    }
  }
  return mas<=P;
}

int main(){
  cin >> N >> P;
  ll T = 1;
  rep(i,N){
    cin >> A[i];
    sum += A[i];
  }
  auto B = divisor(sum);
  rep(i,B.size()){
    if(check(B[i])){
      T = max(B[i],T);
    }
  }
  cout << T << endl;
}
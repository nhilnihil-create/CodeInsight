#include <bits/stdc++.h>
 
using namespace std ;
typedef long long ll;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll ;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<vll> vvll;
typedef vector<str> vstr;
typedef vector<pii> vpii ;
typedef vector<pll> vpll ;
 
#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define CHI 1000000000000000003
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define TS to_string
#define NP next_permutation
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)
 
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数
 
void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}

void solve(vvint kukan,int n){
  int ans = 1;
  int loc = kukan[0][1];
  REP(i,n-1){
    if(kukan[i+1][0]>=loc){
      ans+=1;
      loc = kukan[i+1][1];
    }
  }
  cout << ans <<endl;
}

int main(){
  ll n;
  vvint kukan(100000,vint(2));
  cin >> n;
  REP(i,n){
    int x,l;
    cin >> x;
    cin >> l;
    kukan[i][0]=x-l;
    kukan[i][1]=x+l;
  }
  sort(kukan.begin(),kukan.begin()+n,[](const vint &alpha,const vint &beta){return alpha[1] < beta[1];});
  solve(kukan,n);
}
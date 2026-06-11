#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef string str;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<str> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii ;

#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
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

//-------------------------------------------------
// 
void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}


//-------------------------------------------------
// メモ
/*






*/
//-------------------------------------------------


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n ;
  cin >> n ;
  vll num(n) ;
  set<ll> S ;
  REP(i,n){
    cin >> num[i] ;
    S.insert(num[i]) ;
  }
  if(SZ(S)>=4){
    no() ;
  }
  else{
    if(SZ(S)==1){
      auto itr = S.begin() ;
      ll a = (*itr) ;
      if((a^a)==a){
        yes() ;
      }
      else{
        no() ;
      }
    }
    else if(SZ(S)==2){
      auto itr = S.begin() ;
      ll a = (*itr) ;
      itr++ ;
      ll b = (*itr) ;
      int cnta = 0 ;
      int cntb = 0 ;
      REP(i,n){
        if(num[i]==a){
          cnta++ ;
        }
        else{
          cntb++ ;
        }
      }
      if(2*cnta==cntb && (a^b)==b){
        yes() ;
      }
      else{
        no() ;
      }
    }
    else{
      auto itr = S.begin() ;
      ll a = (*itr) ;
      itr++ ;
      ll b = (*itr) ;
      itr++ ;
      ll c = (*itr) ;
      if((a^b)!=c){
        no() ;
        return 0 ;
      }
      int cnta = 0 ;
      int cntb = 0 ;
      int cntc = 0 ;
      REP(i,n){
        if(num[i]==a){
          cnta++ ;
        }
        else if(num[i]==b){
          cntb++ ;
        }
        else if(num[i]==c){
          cntc++ ;
        }
      }
      if(max({cnta,cntb,cntc})==min({cnta,cntb,cntc})){
        yes() ;
      }
      else{
        no() ;
      }
    }
  }

  return 0 ;
}



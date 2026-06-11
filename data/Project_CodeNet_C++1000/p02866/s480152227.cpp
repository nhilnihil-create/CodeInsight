#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 998244353
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (int)x.size()
#define SP(x)  setprecision((int)x)


using namespace std ;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

//-------------------------------------------------
//コピペするとこ

ll mpow(ll a, ll b){
  ll c = 1 ;
  REP(i,b){
    c = c*a%MOD ;
  }
  return c ;
}



//-------------------------------------------------


int main()
{ 
  int n ;
  cin >> n ;
  ll ans = 1 ;
  
  vector<ll> vec(n) ;
  
  ll m = 0 ;
  
  REP(i,n){
    cin >> vec.at(i) ;
    m = max(m,vec.at(i)) ;
  }
  if(vec.at(0)!=0){
    cout << 0 <<endl ;
    return 0 ;
  }
  
  m++ ;
  
  vector<ll> vecy(m,0) ;
  
  REP(i,n){
    vecy.at(vec.at(i))++ ;
  }
  
  if(vecy.at(0)!=(ll)1){
    cout << 0 <<endl ;
    return 0; 
  }
  
  FOR(i,1,m){
    ans = ans*mpow(vecy.at(i-1),vecy.at(i))%MOD ;
  }
  
  cout <<ans%MOD<<endl ;
  
  return 0 ;
}





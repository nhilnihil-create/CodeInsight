#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
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



//-------------------------------------------------


int main()
{
  ll n, k ;
  cin >> n >> k ;
  ll cnt1 = 0 ;
  ll cnt2 = 0 ;
  ll mod = 1000000007 ;
  ll ans ;
  
  vector<int> vec(n) ;
  
  REP(i,n){
    cin >> vec.at(i) ;
  }
  
  REP(i,n-1){
    FOR(j,i+1,n){
      if(vec.at(i)>vec.at(j)){
        cnt1++ ;
      }
    }
  }
  
  for(int i=n-1; i>=1; i--){
    for(int j=i-1; j>=0; j--){
      if(vec.at(i)>vec.at(j)){
        cnt2++ ;
      }
    }
  }
  
  ans = (k*(k+1)/2%mod*cnt1%mod+k*(k-1)/2%mod*cnt2%mod)%mod ;
  
  cout << ans <<endl ;

  return 0 ;
}


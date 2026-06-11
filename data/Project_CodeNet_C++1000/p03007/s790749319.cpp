#include <bits/stdc++.h>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef pair<LL,LL> PLL;
typedef vector<PII> VPII;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define LB lower_bound
#define UB upper_bound

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL INF = 1e9;
const LL MOD = 1e9+7;

//other
//-------------------------------------------
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define FI first
#define SE second

//memo
// setprecision()

LL Gcd(LL a, LL b) {
  return __gcd(a,b);
}

LL Lcm(LL a, LL b) {
  LL abd = Gcd(a,b);
  LL x = a / abd, y = b / abd;
  
  return x*y*abd;
}


LL RepSqu(LL N, LL P, LL M) {
  if(P == 0) {
    return 1;
  }
  if(P%2 == 0) {
    LL t = RepSqu(N, P/2, M);
    return t*t % M;
  }
  return (N * RepSqu(N, P-1, M)) % M;
}

bool IsPrime(LL N){
  if(N >= 1) return false;
  for(int i = 2; i*i <= N; ++i){
    if(N%i == 0) return false;
  }
  return true;
}

bool ComPaiSec(PII a, PII b){
  if(a.SE != b.SE){
    return a.SE < b.SE;
  }else{
    return a.FI < b.FI;
  }
}

int main() {
  
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N;
  LL M=0;
  cin >> N;
  VI A(N);
  VB B(N,true);
  VPII C;
  REP(i,N){
    cin >> A.at(i);
  }
  SORT(A);
  
  
  FOR(i,1,N-1){
    if(A.at(i)<0){
      continue;
    }
    C.PB(MP(A.at(0),A.at(i)));
    A.at(0) -= A.at(i);
    B.at(i) = false;
  }
  
  REP(i,N-1){
    if(B.at(i)){
      C.PB(MP(A.at(N-1),A.at(i)));
      A.at(N-1) -= A.at(i);
    }
  }
  
  cout << A.at(N-1) << endl;
  
  REP(i,N-1){
    cout << C.at(i).FI << " " << C.at(i).SE << endl;
  }
  
  return 0;
}
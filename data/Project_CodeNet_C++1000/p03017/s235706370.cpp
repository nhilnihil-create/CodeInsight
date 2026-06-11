#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (int)x.size()
#define SP(x)  setprecision((int)x)


using namespace std ;
typedef long long ll;
using Graph = vector<vector<int>>;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
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
  int n, a, b, c, d ;
  string s ;
  cin >> n >> a >> b >> c >> d >> s ;
  a-- ;
  b-- ;
  c-- ;
  d-- ;
  
  if(c<d){
    while(1){
      if(b==d){
        break ;
      }
      if(s[b+1]=='.'){
        b++ ;
      }
      else if(s[b+1]=='#' && s[b+2]=='.' && b+2<SZ(s)){
        b += 2 ;
      }
      else{
        no() ;
        return 0 ;
      }
    }
    while(1){
      if(a==c){
        yes() ;
        return 0 ;
      }
      if(s[a+1]=='.'){
        a++ ;
      }
      else if(s[a+1]=='#' && s[a+2]=='.' && a+2<SZ(s)){
        a += 2 ;
      }
      else{
        no() ;
        return 0 ;
      }
    }
  }
  else{
    vint vec(n,0) ;
    for(int i=a;i<n-2;i++){
      if(s[i]=='.'){
        if(s[i+1]=='.' && s[i+2]=='.'){
          vec[i+1] = 1 ;
        }
      }
    }
    /*
    REP(i,n){
      cout << vec[i] <<endl ;
    }
    */
    while(1){
      if(a==c){
        break ;
      }
      if(s[a+1]=='.'){
        a++ ;
      }
      else if(s[a+1]=='#' && s[a+2]=='.' && a+2<SZ(s)){
        a += 2 ;
      }
      else{
        no() ;
        return 0 ;
      }
    }
    bool f = false ;
    if(vec[b]==1){
      f = true  ;
    }
    while(1){
      if(b==d){
        if(f){
          yes() ;
          return 0 ;
        }
        else{
          no() ;
          return 0 ;
        }
      }
      
      if(s[b+1]=='.'){
        b++ ;
        if(vec[b]==1){
          f = true ;
        }
      }
      else if(s[b+1]=='#' && s[b+2]=='.' && b+2<SZ(s)){
        b += 2 ;
        if(vec[b]==1){
          f = true ;
        }
      }
      else{
        no() ;
        return 0 ;
      }
    }
  }
  return 0 ;
}


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
string strReplace(string s,string target, string replacement){
    if (!target.empty()) {
      std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll MOD = 1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair

bool DEBUG = 0;

template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}

// a1^a4 = a3
// a2^a5 = a4
// a3^a1 = a5
// a4^a2 = a1     a3^a5 = a3^a5^a4^a1 -> a4^a1 = 0
// a5^a3 = a2     a4^a1 = a4^a1^a2^a5 -> a5^a2 = 0

int N;
vector<int> a;

bool check1(){ // 全部ゼロ
  return (a[N-1]==0);
}

bool check2(){ // x 0 x x 0 x
  if(N%3>0){ return false;}
  return (a[0]==0 && a[N/3-1]==0 && a[N/3]==a[N-1]);
}

bool check3(){ // x y z x y z
  if(N%3>0){ return false;}
  if( a[0]==a[N/3-1] && a[N/3]==a[N/3*2-1] && a[N/3*2]==a[N-1]){
    return (a[0]^a[N/3]^a[N/3*2])==0;
  }else{
    return false;
  }
}

int main(){
  cin >> N;
  REP(i,N){
    int x; cin >> x;
    a.push_back(x);
  }
  sort(ALL(a));
  bool ok = 0;
  ok += check1();
  ok += check2();
  ok += check3();
  cout << (ok?Liny:Linn);
}
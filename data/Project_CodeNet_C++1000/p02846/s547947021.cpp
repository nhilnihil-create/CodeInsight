#include <bits/stdc++.h>
using namespace std;
// type alias
typedef long long LL;
typedef pair<int,int> II;
typedef tuple<int,int,int> III;
typedef vector<int> VI;
typedef vector<string> VS;
typedef unordered_map<int,int> MAPII;
typedef unordered_set<int> SETI;
template<class T> using VV=vector<vector<T>>;
// minmax
template<class T> inline T SMIN(T& a, const T b) { return a=(a>b)?b:a; }
template<class T> inline T SMAX(T& a, const T b) { return a=(a<b)?b:a; }
// repetition
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n)  for(int i=0;i<=(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
// collection
#define ALL(c) (c).begin(),(c).end()
// DP
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define ZERO(dp) memset(dp, 0, sizeof(dp))
// stdout
#define println(args...) fprintf(stdout, ##args),putchar('\n');
// debug cerr
template<class Iter> void __kumaerrc(Iter begin, Iter end) { for(; begin!=end; ++begin) { cerr<<*begin<<','; } cerr<<endl; }
void __kumaerr(istream_iterator<string> it) { (void)it; cerr<<endl; }
template<typename T, typename... Args> void __kumaerr(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<"="<<a<<", ",__kumaerr(++it, args...); }
template<typename S, typename T> std::ostream& operator<<(std::ostream& _os, const std::pair<S,T>& _p) { return _os<<"{"<<_p.first<<','<<_p.second<<"}"; }
#define __KUMATRACE__ true
#ifdef __KUMATRACE__
#define dump(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); __kumaerr(_it, args); }
#define dumpc(ar) { cerr<<#ar<<": "; FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }
#define dumpC(beg,end) { cerr<<"~"<<#end<<": "; __kumaerrc(beg,end); }
#else
#define dump(args...)
#define dumpc(ar)
#define dumpC(beg,end)
#endif
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}
// $ cp-batch Test | diff Test.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address Test.cpp && ./a.out

/*

 6/30/2020

 9:58-10:44 give up

 7/2/2020

 13:25-14:25

 */

const LL Inf=1e18;
LL A1,A2,B1,B2,T1,T2;

LL solve() {
  LL a1=T1*A1,a2=T2*A2,b1=T1*B1,b2=T2*B2;
  if(a1<b1) swap(a1,b1),swap(a2,b2);
  if(a1+a2>b1+b2) return a1==b1;
  if(a1+a2==b1+b2) return Inf;
  LL good=Inf+10,bad=0;

  auto f=[&](__int128_t x) -> int {
    __int128_t t1=(x+1)/2,t2=x-t1;
    auto res=t1*b1+t2*b2-(t1*a1+t2*a2);
    if(res==0) return 0;
    return res>0?1:-1;
  };

  while(abs(good-bad)>1) {
    LL x=(good+bad)/2;
    bool res=f(x+1)>0&&f(x)>0;
    (res?good:bad)=x;
  }
  dump(a1,a2,b1,b2,a1+a2,b1+b2);
  dump(good,f(good+2),f(good+1),f(good),f(good-1),f(good-2),f(good-3));

  return good-1-(f(good-1)==0);

/*
  if(A1*T1+A2*T2>B1*T1+B2*T2) return 0;
  if(T1*(A1-B1)==T2*(B2-A2)) return Inf;
  LL good=1,bad=Inf+10;
  while(abs(good-bad)>1) {
    LL mid=(good+bad)/2;
    LL a=T1*(A1-B1)+T2*(A2-B2);
    LL b=T1*(B1-A1);
    bool res=a>=b/mid;
    dump(mid,res,a,b,b/mid);
    (res?good:bad)=mid;
  }

  LL a=T1*(B1-A1)/(T1*(A1-B1)+T2*(A2-B2));
  dump(a);

  dump(good);
  return good;*/
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(12)<<fixed;

  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  LL res=solve();
  if(res>=Inf) cout<<"infinity"<<endl;
  else cout<<res<<endl;

  return 0;
}

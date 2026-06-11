#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define AND(x,y,z) 
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define DUMPP(xs) for (auto x:xs) cout<<'('<<x.first<<','<<x.second<<')';cout<<endl
#define FOR(i,a,b) for (ll i=(ll)(a);i<(ll)(b);++i)
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)
#define YES(cond) cond ? OUT("YES") : OUT("NO")
#define Yes(cond) cond ? OUT("Yes") : OUT("No")

template<class T> T gcd(const T x,const T y){if(!y){return x;}return gcd(y,x%y);}
template<class T> T lcm(const T x,const T y){return x/gcd(x,y)*y;};
template<class T> T modpow(const T x,const T n,const T mod) {
  T res=1;while(n>0){if(n%2)res=res*x%mod;x=x*x%mod;n/=2;};return res;
}
template<class T> bool alltrue(const T &a){return all_of(ALL(a),[](bool x){return x;});}
template<class T> bool anytrue(const T &a){return any_of(ALL(a),[](bool x){return x;});}
template<class T> bool contain(const T &a,const T &b){for(auto x:b){if (a.find(x)==a.end()){return false;}}return true;}
template<class T> bool mmax(T &m,const T q){ if (m < q) {m = q; return true;} else return false; }
template<class T> bool mmin(T &m,const T q){ if (m > q) {m = q; return true;} else return false; }
template<class T> int siz(const T &a) {return (int)a.size();}
template<class T> set<T> devisers(T n) {
  set<T> res;for(T i=1;i<(T)sqrt(n)+1;i++){if(n%i==0){res.insert(i);res.insert(n/i);}}return res;
}
template<class T> void concat(T &a, const T &b){a.insert(a.end(),b.begin(),b.end());}
template<class T> void getand(const T &a,const T &b,T &c) {
  set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}
template<class T> void getor(const T &a,const T &b,T &c) {
  set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}

typedef long long ll;
typedef pair<ll, ll> P;

const int MOD=1e9+7;

int main() {
  ll T1,T2,A1,A2,B1,B2;cin>>T1>>T2>>A1>>A2>>B1>>B2;

  int first_winner = A1<B1 ? 1 : 0;
  int second_winner = A2<B2 ? 1 : 0;

  // 絶対追いつかない
  if (first_winner==second_winner) {
    OUT(0);
    return 0;
  }

  ll first_gap = abs(A1-B1)*T1;
  ll second_gap = abs(A2-B2)*T2;

  if (first_gap == second_gap) {
    OUT("infinity");
    return 0;
  }
  if (first_gap > second_gap) {
    OUT(0);
    return 0;
  }
  // 毎回この数だけ差がついていく
  ll total_gap = second_gap-first_gap;

  if (first_gap%total_gap==0) {
    OUT(first_gap/total_gap*2);
  } else {
    OUT(first_gap/total_gap*2+1);
  }

  return 0;
}
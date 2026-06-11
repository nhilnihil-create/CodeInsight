#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define fs first
#define sd second
#define couts(x) cout << (x) << (" ")
#define coutn(x) cout << (x) << ("\n")
#define endl "\n"

template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T1, typename T2> std::istream &operator>>(std::istream &is, std::pair<T1,T2> &p){is >> p.first >> p.second; return is; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::deque<T> &vec){ os << "deque["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }

template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;
template<class T> using V3 = V<V2<T>>;
using comp = complex<ld>;
const ld PI = acos( (ld)(-1) );

void solve(){
  int n; cin >> n;
  V<comp> vv;
  FOR(i,0,n){
    int x, y;
    cin >> x >> y;
    if(x==0 && y==0) continue;
    vv.push_back(comp(x,y));
  }
  n = (int)vv.size();
  sort(ALL(vv),[&](comp c1, comp c2){
    if( arg(c1)< arg(c2) ) return true;
    return false;
  });
  ld ansr = 0;
  /*FOR(i,0,n){
    comp c(0,0);
    FOR(j,0,n){
      if(abs(c)<abs(c+vv[(i+j)%n])) c += vv[(i+j)%n];
    }
    if( abs(c)>ansr ) ansr = abs(c);
  }*/
  {
    //coutn(vv);
    int l=0, r=0; comp c(0,0);
    for(;l<n;++l){
      //couts(l); couts(":");
      while( abs(c)<abs(c+vv[r]) ){
        c += vv[r];//couts("  ");couts(r); coutn(c);
        ansr = max(ansr,abs(c));
        (++r)%=n;
        if(r==l) break;
      }//couts("  ");couts(r); couts(c); couts(abs(c));coutn(ansr);
      //c -= vv[r];
      //r = (2*n+r-1)%n;
      c -= vv[l];
      ansr = max(ansr, abs(c));
      if(l==r) {c = comp(0,0); (++r)%=n;}
      //couts("  ");couts(r); couts(c);coutn(ansr);
    }
  }
  std::cout << std::fixed << std::setprecision(20);
  couts(ansr);
}

int main(){
  solve();
  return 0;
}
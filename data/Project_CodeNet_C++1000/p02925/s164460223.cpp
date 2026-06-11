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


struct timet{
  std::vector<std::chrono::system_clock::time_point> tp;
  timet(){
    tp = std::vector<std::chrono::system_clock::time_point>(10);
  }
  timet(int n) {
    tp = std::vector<std::chrono::system_clock::time_point>(n);
  }
  void recordtime(int x){
    tp[x] = std::chrono::system_clock::now();
  }
  int caltime(int x, int y, int option = 0){
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp[y] - tp[x]).count();
  }
};



template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;


void solve(){
  timet tm(5);
  tm.recordtime(0);
  int n; cin >> n;
  V2<int> a(n, V<int>(n));
  FOR(i,0,n) FOR(j,0,n-1) {cin >> a[i][j]; a[i][j]--;}
  int l = 0, r = n*(n-1)/2+10, m;
  bool tle = false;
  while(r-l>1){
    m = (l+r)>>1;
    bool psbl = true;
    [&](){
      V<int> mat(n,0);
      FOR(i,0,m){
        tm.recordtime(1);
        if(tm.caltime(0,1)>1000) {tle = true; return;}
        V<bool> b(n,false);
        bool flg = false;
        FOR(j,0,n){
          if(b[j]) continue;
          if(mat[j]>n-1) continue;
          int comt = a[j][mat[j]];
          if(!b[comt] && a[comt][mat[comt]]==j){
            b[comt] = true;
            b[j] = true;
            mat[comt]++;
            mat[j]++;
            flg = true;
          }
        }
        if(!flg) break;
      }
      FOR(i,0,n) if(mat[i]<n-1) { psbl = false; return;}
      return;
    }();
    if(psbl) r = m;
    else l = m;
    if(tle) {cout << (ll)n*(n-1)/2; return;}
  }
  if(r>n*(n-1)/2+2) cout << -1 << '\n';
  else cout << r << '\n';
}

int main(){
  solve();
  return 0;
}
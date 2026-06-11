#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)


template<typename T>
struct MP {
  int n;
  T t;
  std::vector<int> a;
  MP() {}
  MP(const T& t): t(t) {
    n = t.size();
    a = std::vector<int>(n+1);
    a[0] = -1;
    int j = -1;
    for (int i = 0; i < n; ++i) {
      while (j != -1 && t[j] != t[i]) j = a[j];
      j++;
      a[i+1] = j;
    }
  }
  int operator[](int i) { return a[i];}
  std::vector<int> findAll(const T& s) {
    vector<int> res;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      while (j != -1 && t[j] != s[i]) j = a[j];
      j++;
      if (j == n) {
        res.push_back(i-j+1);
        j = a[j];
      }
    }
    return res;
  }
};

template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;

void solve(){
  int n; string s; cin >> n >> s;
  int nl = 0, nr = n/2 + 1, nm;
  while(nr-nl>1){
    nm = (nl+nr)/2;
    bool psbl = false;
    FOR(i,0,n-nm){
      MP<string> mp( s.substr(i,nm) );
      vector<int> tbl = mp.findAll( s.substr(i+nm,n-nm-i) );
      if(!tbl.empty()){
        //sa = s.substr(i,nm);
        psbl = true;
        break;
      }
    }
    if(psbl) nl = nm;
    else nr = nm;
  }
  //if(sa.empty()) sa = sb;
  cout << nl << '\n';
}

int main(){
  solve();
  return 0;
}
#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

int main(){

  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  REP(i,n) a[i] = l + i; //美味しさ
  debug(a);
  //総和
  int sum = 0;
  REP(i,n) sum += a[i];
  int minx = 1000000000;
  int ans;
  REP(i,n){
    int tmps = 0;
    REP(j,n){
      if(i == j) continue;
      tmps += a[j];
    }
    if(minx > abs(sum - tmps)){
      minx = abs(sum-tmps);
      ans = tmps;
    }
  }
  cout << ans << endl;

  return 0;
}

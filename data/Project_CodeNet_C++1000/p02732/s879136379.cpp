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
#define REP(i,n) for (int i = 0; i <(n); ++i)
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
  //input
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  //集計numa[x] を用意
  const int NMAX = 200010;
  vector<int> numa(NMAX);
  REP(i,n){
    numa[a[i]]++;
  }
  //sumの計算
  ll sum = 0;
  REP(i,NMAX){
    if(numa[i] == 0) continue;
    int na = numa[i];
    sum += (ll)na*(na-1)/2;
  }

  //各数字について出力　先に計算すると定数倍早いけど必要ない
  REP(i,n){
    int na = numa[a[i]];
    if(na == 1){
      cout << sum << endl;
    }
    else{
      ll sum2 = sum - na*(na-1)/2 + (na-1)*(na-2)/2;
      cout << sum2 << endl;
    }
  }
  return 0;
}
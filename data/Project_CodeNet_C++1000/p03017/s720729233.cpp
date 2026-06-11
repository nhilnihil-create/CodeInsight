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
  int n, a, b, c, d;
  cin >>  n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string s;
  cin >> s;

  bool ok = true;

  REP2(i,a,c+1) {
    if(s[i] == '#' && s[i+1] == '#') ok = false;
  }
  REP2(i, b, d+1){
      if(s[i] == '#' && s[i+1] == '#') ok = false;
  }
  
  if(!ok){
    cout << "No" << endl;
    return 0;
  }

  if(c < d){
    cout  << "Yes" << endl;
    return 0;
  }

  ok = false;

  REP2(i,b,d+1){
    if(s[i+1] == '.' && s[i] == '.' && s[i-1] == '.'){
      ok = true;
      break;
    }
  }

  if(ok){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)
constexpr int INF = 1e9;
//constexpr ll INF = 1LL << 61;
constexpr int mod = 1e9+7;

int main(){
  string S;
  cin >> S;
  if(S.back() == 's'){
    S+="es";
  }
  else{
    S += "s";
  }
  cout << S << endl;
  return 0;
}

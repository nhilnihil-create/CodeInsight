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
  bool ans = false;
  int N;
  cin >> N;
  int cnt =0;
  REP(i, N){
    int d1, d2;
    cin >> d1 >> d2;
    if(d1 == d2){
      cnt++;
    }
    else{
      cnt = 0;
    }
    if(cnt == 3){
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}

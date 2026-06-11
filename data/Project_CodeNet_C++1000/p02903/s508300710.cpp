#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// constexpr ll INF = 1LL << 60;
int main(){
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  REP(i, H){
    REP(j, W){
      if(i < B && j < A || B<=i && A<=j){
        cout << 0;
      }
      else{
        cout << 1;
      }
    }
    cout << endl;
  }
  return 0;
}


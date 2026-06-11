#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(n);++i)
#define MOD 1000000007 
using namespace std;
typedef long long LL;

int main(){
  int K, Q, D[5000];
  cin >> K >> Q;
  REP(i, K) {
    cin >> D[i];
  }
  REP(_, Q) {
    LL N, X, M, E[5000];
    cin >> N >> X >> M;
    X %= M;
    LL ret = N - 1;
    LL a_last = X;
    REP(i, K) {
      LL count = (N-1) / K + ((N-1) % K > i ? 1 : 0);
      a_last += count * (D[i] % M);
      if(D[i] % M == 0) {
        ret -= count;
      }
    }
    ret -= a_last / M;
    cout << ret << endl;
  }
}
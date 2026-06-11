#include <bits/stdc++.h>
using namespace std;

long INF = 1e16;

long divPlusOneIfModExist(long target, long div) {
  return (target+div-1L)/div;
}

int main() {
  long N;
  cin >> N;

  long A[N+1];
  for (int i = 0; i <= (int)N; i++) {
    cin >> A[i];
  }  
  
  long maxNodes[N+1];
  maxNodes[0] = 1L;
  for (int i = 1; i <= N ; i++) {
    maxNodes[i] = min(2*(maxNodes[i-1] - A[i-1]),INF);
  }
  
  long ans = 0L;
  long currentNodes = 0L;
  for (int i = (int)N; i >= 0 ; i--) {
    // Check ng;
    if (divPlusOneIfModExist(currentNodes, 2L)>maxNodes[i]-A[i]) {
        cout << -1 << endl;
        return 0;
    }
    currentNodes = min(maxNodes[i],currentNodes+A[i]);
    ans+=currentNodes;
  }

  cout << ans << endl;
  return 0;
}
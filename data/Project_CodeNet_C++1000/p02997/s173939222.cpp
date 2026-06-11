#include<bits/stdc++.h>
using namespace std;

long long binomial(int N, int K) {
    if(K < 0 || N < K) return 0;
    long long ret = 1;
    for(long long i = 1; i <= K; ++i) {
        ret *= N--;
        ret /= i;
    }
    return ret;
}

int N,K;

signed main() {
  cin >> N >> K;
  int mx = binomial(N-1, 2);
  if( K > mx ){puts("-1"); return 0;}

  int addition = mx - K;

  int M = N-1 + addition;
  cout << M << endl;
  for(int i=2; i<=N; i++) cout << "1 " << i << endl;
  for(int i=2; i<=N; i++) for(int j=i+1; j<=N; j++) {
    if(addition-- == 0) return 0;
    cout << i << " " << j << endl;
  }
}

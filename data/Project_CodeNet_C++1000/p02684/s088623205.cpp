#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  int N;
  int64_t K;
  cin >> N >> K;
  int A[N];
  rep(i,N)
    cin >> A[i];
  
  int d[N];
  rep(i,N)
    d[i] = -1;
  
  int nA = 0;
  int nt = 0;
  while (true){
    if (d[nA] != -1){
      nt -= d[nA];
      break;
    }
    d[nA] = nt;
    nA = A[nA]-1;
    nt++;
  }
  
  int rest = -1;
  int res = -1;
  rep(i,N){
    if (d[i] == -1)
      continue;
    if ((K-d[i])%nt == 0 && d[i] > rest && K>=d[i]){
      rest = d[i];
      res = i+1;
    }
  }
  
  cout << res << endl;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  int N;
  cin >> N;
  int L[N];
  rep(i,N)
    cin >> L[i];
  
  int res = 0;
  for (int i = 0; i < N; i++){
    for (int j = i+1; j < N; j++){
      for (int k = j+1; k < N; k++){
        if (L[i] == L[j] || L[j] == L[k] || L[k] == L[i])
          continue;
        if (abs(L[i]-L[j]) < L[k] && L[k] < L[i]+L[j])
          res++;
      }
    }
  }
  
  cout << res << endl;
}
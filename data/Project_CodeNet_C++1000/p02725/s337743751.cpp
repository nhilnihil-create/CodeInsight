#include <bits/stdc++.h>
using namespace std;

int main(){
  int K, N;
  cin >> K >> N;
  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];
  int m = 0;
  for (int i = 0; i < N - 1; i++){
    m = max(m, a[i + 1] - a[i]);
  }
  m = max(m, K - a[N - 1] + a[0]);
  cout << K - m;
}
  

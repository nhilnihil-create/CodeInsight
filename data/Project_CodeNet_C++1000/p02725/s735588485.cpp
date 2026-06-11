#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  int N;
  cin >> K;
  cin >> N;

  int a[N+1];

  for(int i = 1; i<=N; i++){
    cin >> a[i];
  }

  int range[N];

  for(int i = 1; i<N; i++){
    range[i] = a[i+1] - a[i];
  }

  range[N] = K - a[N] + a[1];

  int max = range[1];
  for (int i = 1; i <= N; i++) {
      if (max < range[i]) {
          max = range[i];
      }
  }

  cout << K - max << endl;
}

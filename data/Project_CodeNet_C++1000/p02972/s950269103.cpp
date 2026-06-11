#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<int> c(N, 0);
  for (int i = N - 1; i >= 0; i--){
    c[i] = a[i];
    for (int j = 2 * i + 1; j < N; j += i + 1){
      c[i] ^= c[j];
    }
  }
  vector<int> b;
  for (int i = 0; i < N; i++){
    if (c[i] == 1){
      b.push_back(i + 1);
    }
  }
  int M = b.size();
  cout << M << endl;
  for (int i = 0; i < M; i++){
    cout << b[i];
    if (i < M - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
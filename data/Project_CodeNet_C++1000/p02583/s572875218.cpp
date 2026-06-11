#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++){
    int a = vec[i];
    for (int j = i + 1; j < N; j++){
      int b = vec[j];
      for (int k = j + 1; k < N; k++){
        int c = vec[k];
        int M = max(max(a, b), c);
        if (a != b && b != c && c != a && M < a + b + c - M){
          ans++;
        }
      }
    }
  }
  cout << ans;
}


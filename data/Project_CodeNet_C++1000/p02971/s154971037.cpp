#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int V[N];
  for (int i = 0; i < N; i++){
    cin >> V[i];
  }
  int max_1 = 0, max_2 = 0, cnt = 0;
  for (int i = 0; i < N; i++){
    if (V[i] > max_1){
      max_1 = V[i];
      cnt = 0;
    }
    if (V[i] == max_1){
      cnt++;
    }
  }
  for (int i = 0; i < N; i++){
    if (V[i] > max_2 && V[i] != max_1) max_2 = V[i];
  }
  for (int i = 0; i < N; i++){
    if (V[i] == max_1 && cnt < 2) cout << max_2 << endl;
    else cout << max_1 << endl;
  }
  return 0;
}
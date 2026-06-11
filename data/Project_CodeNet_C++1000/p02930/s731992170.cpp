#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      int k = 0;
      while ((i >> k & 1) == (j >> k & 1)){
        k++;
      }
      cout << k + 1;
      if (j < N - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
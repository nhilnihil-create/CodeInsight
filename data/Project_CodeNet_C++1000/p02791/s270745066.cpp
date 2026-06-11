#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int P[N];
  for (int i = 0; i < N; i++){
    cin >> P[i];
  }
  int m = P[0], cnt = 1;
  for (int i = 1; i < N; i++){
    if (m > P[i]){
      cnt++;
      m = P[i];
    }
  }
  cout << cnt << endl;
}
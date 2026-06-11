#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, tmp;
  cin >> N;
  int result[N];
  for (int i = 0; i < N; i++){
    cin >> tmp;
    result[tmp - 1] = i + 1;
  }
  for (int i = 0; i < N; i++){
    cout << result[i];
    if(i != N-1) cout << " ";
  }
  return 0;
}
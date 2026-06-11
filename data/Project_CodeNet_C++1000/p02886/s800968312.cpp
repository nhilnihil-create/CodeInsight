#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++){
    cin >> d[i];
  }
  
  int sum = 0, ans = 0;
  for (int i = 0; i < N; i++){
    sum += d[i];
  }
  
  for (int i = 0; i < N; i++){
    ans += (sum - d[i]) * d[i];
  }
  
  cout << ans / 2 << endl;
}
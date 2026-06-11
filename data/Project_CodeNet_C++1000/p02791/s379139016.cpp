#include <bits/stdc++.h>
using namespace std;

int main(){
  long N, ans = 1, min = 0, P;
  cin >> N;
  cin >> min;
  for (int i = 1; i < N; i++){
    cin >> P;
    if (min >= P){
      min = P;
      ans ++;
    }
  }
  cout << ans << endl;
}
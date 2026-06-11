#include <bits/stdc++.h>
using namespace std;
int main(){
  int M, D;
  cin >> M >> D;
  int ans = 0;
  for (int i = 1; i <= D; i++){
    int d1 = i % 10;
    int d2 = i / 10;
    if (d1 >= 2 && d2 >= 2 && d1 * d2 <= M){
      ans++;
    }
  }
  cout << ans;
}
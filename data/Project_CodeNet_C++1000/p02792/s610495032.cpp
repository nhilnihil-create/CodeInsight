#include <bits/stdc++.h>
using namespace std;

int getHeadNum(int n) {
  while(n/10>0){
    n /= 10;
  }
  return n;
}
int getFooterNum(int n) {
  return n%10;
}

int main(){
  int N;
  cin >> N;
  
  long long memo[10][10];
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      memo[i][j]=0;
    }
  }
  
  for (int i = 1; i <= N; i++) {
    memo[getHeadNum(i)][getFooterNum(i)]++;
  }
  
  long long ans = 0;
  for (int i = 1; i < 10; i++){
    for (int j = 1; j < 10; j++){
      ans += memo[i][j]*memo[j][i];
    }
  }
  
  cout << ans << endl;
  return 0;
}
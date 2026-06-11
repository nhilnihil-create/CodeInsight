#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int head(int x){
  while(x>=10){
    x /= 10;
  }
  return x;
}

int foot(int x){
  return x%10;
}

int main(){
  int N;cin >> N;
  vector<vector<int>> M(10,vector<int>(10,0));
  for(int i=1;i<=N;i++){
    M[head(i)][foot(i)] ++;
  }
  ll sum = 0;
  for(int i=1;i<=9;i++){
    sum += M[i][i]*M[i][i];
    for(int j=i+1;j<=9;j++){
      sum += M[i][j]*M[j][i]*2;
    }
  }
  cout << sum << endl;
}
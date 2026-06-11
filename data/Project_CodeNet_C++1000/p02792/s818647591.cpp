#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> cnt(10, vector<int>(10));
  for(int i = 1; i <= n; i++){
    for(int j = 100000; j > 0; j /= 10){
      if(i / j > 0 && i / j < 10){
        cnt.at(i/j).at(i%10)++;
      }
    }
  }
  
  long long ans = 0;
  for(int i = 1; i < 10; i++){
    for(int j = 1; j < 10; j++){
      long long a = cnt.at(i).at(j), b = cnt.at(j).at(i);
      ans += a * b;
    }
  }
  
  cout << ans << endl;
}
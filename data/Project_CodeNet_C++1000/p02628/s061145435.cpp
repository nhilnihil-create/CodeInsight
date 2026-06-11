#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  
  vector<int> fruits(N);
  
  for(int i = 0; i < N; i++){
    cin >> fruits.at(i);
  }
  sort(fruits.begin(),fruits.end());
   int ans = 0; 
    for(int i = 0; i < K; i++){
      ans += fruits.at(i);
    }
  cout << ans << endl;
}
      
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
    cin >> N;
  
  vector<long long> k(N);
  for(int i = 0;i < N; i++){
    cin >> k.at(i);
}
  long long ans = k.at(0);
  bool t = true;
  sort(k.begin(), k.end());

  for(int i = 1;i < N; i++){
    if(k.at(i) <= 1000000000000000000/ans){
      ans *= k.at(i);
    } else {
      t = false;
      break;}
  }
  if(k.at(0) == 0){cout << "0" << endl;}
  else if(t){cout << ans << endl;}
  else {cout << "-1" << endl;}
}
      
    
    

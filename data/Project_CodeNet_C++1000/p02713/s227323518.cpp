#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int k;
  cin >> k;
  
  vector<int> vec;
  for(int a = 1; a < k+1; a++){
    for(int b = 1; b < k+1; b++){
      for(int c = 1; c < k+1; c++){
        vec.push_back(__gcd(__gcd(a, b), c));
      }
    }
  }
  
  int ans = 0;
  for(int i = 0; i < vec.size(); i++) ans += vec[i];
  
  cout << ans << endl;
  return 0;
}
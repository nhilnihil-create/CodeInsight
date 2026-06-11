#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  
  vector<int> A;
  for(int i = 1; i < n+1; i++){
    if(i % 3 != 0 && i % 5 != 0) A.push_back(i);
  }
  
  ll ans = 0;
  for(int i = 0; i < A.size(); i++) ans += A[i];
  
  cout << ans << endl;
  return 0;
}
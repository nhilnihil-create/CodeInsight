#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> t[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i != j){
        ans += t[i] * t[j];
      }
    }
  }
  cout << ans / 2 << endl;
}
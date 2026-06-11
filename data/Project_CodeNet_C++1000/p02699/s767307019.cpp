#include<bits/stdc++.h>
using namespace std;

int main(void){
  int S, W;
  bool ans = true;
  cin >> S >> W;
  if(W >= S)
    ans = false;
  if(ans) cout << "safe" << "\n";
  else cout << "unsafe" << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string S;
  cin >> S;
  int x = S.size(), ans=0;
  
  for(int i=0; i<x/2; i++) {
    if(S.at(i) != S.at(x-1-i)) ans++;
  }

  cout << ans << endl;
  
}
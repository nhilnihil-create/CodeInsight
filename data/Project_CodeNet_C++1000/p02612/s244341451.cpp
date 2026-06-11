#include <bits/stdc++.h>
using namespace std;

int main() {

  int X, ans=0;
  
  cin >> X;
  
  if(X%1000==0) ans=0;
  
  else ans=(X/1000+1)*1000-X;
  
  cout << ans << endl;
     
}
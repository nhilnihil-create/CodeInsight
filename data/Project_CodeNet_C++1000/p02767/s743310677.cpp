#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
  int n;
  int sum,pl,pu;
  long ansl,ansu,ans;
  sum = 0;
  pl = 0;
  pu = 0;
  ans = 0;
  ansl = 0;
  ansu = 0;
  cin >> n;
  vector<int> x(n);

  for(int i = 0; i < n; i++) cin >> x[i];
  for(int i = 0; i < n; i++){
    sum += x[i];
  }

  pl = sum / n;
  pu = pl + 1; 

  for(int i = 0; i < n; i++) ansl += (x[i] - pl) * (x[i] - pl);
  for(int i = 0; i < n; i++) ansu += (x[i] - pu) * (x[i] - pu);

  ans = min(ansl,ansu);

  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++){
    cin >> p.at(i);
  }
  
  int cnt=0;
  int minimum = 1e9;
  for(int i=0;i<n;i++){
    minimum = min(minimum,p[i]);
    if(minimum == p[i]) cnt++;
  }
  
  cout << cnt << endl;
  
  return(0);
}
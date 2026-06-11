#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,x[200];
  cin >> n;
  for(int i = 0; i < n; i++) 
    cin >> x[i];
  
  sort(x,x+n);
  
  int mi = 10000000;
  for(int i = x[0]; i <= x[n-1]; i++) {
    int sum = 0;
    for(int j = 0; j < n; j++) {
      sum += (x[j] - i) * (x[j] - i);
    }
    mi = min(mi, sum);
  }  
  cout << mi << endl;
  return 0;
}
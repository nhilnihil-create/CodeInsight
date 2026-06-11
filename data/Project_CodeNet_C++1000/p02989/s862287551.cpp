#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,d[200000];
  cin >> n;
  for(int i = 0; i < n; i++) 
    cin >> d[i];
  
  sort(d,d+n);
  
  int sum = 0, t = d[n/2 - 1] + 1;
  while(t != d[n/2]+1) {
    sum++;
    t++;
  }
  cout << sum << endl;
  return 0;
}
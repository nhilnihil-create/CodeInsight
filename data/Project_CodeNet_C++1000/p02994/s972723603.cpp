#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n,L,t[300],sum = 0;
  cin >> n >> L;
  for(int i = 0; i < n; i++) {
    t[i] = L+i;
    sum += t[i];
  }
  
  int m = 400, a;
  for(int i = 0; i < n; i++) {
    if(m > abs(t[i])) {
      m = abs(t[i]);
      a = i;
    }
  }
  if(t[a] >= 0)
    cout << sum-m << endl;
  else 
    cout << sum+m << endl;
}
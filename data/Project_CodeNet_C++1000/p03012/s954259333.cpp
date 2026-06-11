#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,w[110],sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> w[i];
    sum += w[i];
  }
  
  int mi = 100000;
  for(int t = 0; t < n-1; t++) {
    int s1 = 0;
    for(int j = 0; j <= t; j++) {
      s1 += w[j];
    }
    int s2 = sum -s1;
    mi = min(mi, abs(s1-s2));
  }
 
  cout << mi << endl;
}
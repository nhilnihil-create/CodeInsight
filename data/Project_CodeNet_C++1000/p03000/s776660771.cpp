#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,x,L[110];
  cin >> n >> x;
  for(int i = 0; i < n; i++)
    cin >> L[i];
  
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += L[i];
    if(sum > x) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << n+1 << endl;
}
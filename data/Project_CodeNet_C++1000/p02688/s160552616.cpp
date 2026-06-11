#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,k,d[110],A[110][110];
  cin >> n >> k;

  for(int i = 0; i < k; i++) {
    cin >> d[i];
    for(int j = 0; j < d[i]; j++)
      cin >> A[i][j];
  }
  
  int sum = 0;
  for(int m = 1; m <= n; m++) {
    for(int i = 0; i < k; i++) {
      for(int j = 0; j < d[i]; j++) {
        if(m == A[i][j]) goto Loop1;
      }
    }
    sum++;
    Loop1: ;
  }
  cout << sum << endl;
}
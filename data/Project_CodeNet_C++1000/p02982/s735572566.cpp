#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,d,A[20][20],num = 0;
  cin >> n >> d;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < d; j++)
      cin >> A[i][j];
  }
  
  for(int i = 0; i <= n-2; i++) {
    int sum = 0;
    for(int j = i+1; j <= n-1; j++) {
      sum = 0;
      for(int k = 0; k < d; k++) {
        sum += (A[i][k]-A[j][k])*(A[i][k]-A[j][k]);
      }
      double dist = sqrt(sum);
      if(dist == (int)dist) num++;
    }
  }
  cout << num << endl;
}
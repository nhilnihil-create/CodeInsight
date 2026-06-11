#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,m,A[1100000],sum = 0;
  cin >> n >> m;
  for(int i = 0; i <m; i++) {
    cin >> A[i];
    sum += A[i];
  }
  if(sum <= n) cout << n-sum << endl;
  else cout << "-1" << endl;
}
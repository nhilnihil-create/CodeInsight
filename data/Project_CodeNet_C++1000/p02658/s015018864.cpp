#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  long n,A[110000],sum = 1;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> A[i];

  for(int i = 0; i < n; i++) {
    if(A[i] == 0) {
      cout << "0" << endl;
      return 0;
    }
  }

  for(int i = 0; i < n; i++) {
    if(A[i] > 1000000000000000000/sum) {
      cout << "-1" << endl;
      return 0;
    }
    else sum *= A[i];
  }
  cout << sum << endl;
}
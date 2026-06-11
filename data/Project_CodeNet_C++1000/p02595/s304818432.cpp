#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  long n,d,x[210000],y[210000];
  cin >> n >> d;

  for(int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  int sum = 0;
  
  for(int i = 0; i < n; i++) {
    if((x[i]*x[i] + y[i]*y[i]) <= d*d) sum++;
  }

  cout << sum << endl;
}
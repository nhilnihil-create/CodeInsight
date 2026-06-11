#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;

  int sum = 0;
  for(int i = 1; i <= k; i++) {
    if(i <= a) sum++;
    else if(i <= a+b) continue;
    else sum--;
  }
  cout << sum << endl;
}
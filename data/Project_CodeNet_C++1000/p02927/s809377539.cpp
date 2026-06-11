#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  int M, D, ans;
  cin >> M >> D;
  ans=0;
  for (int m=1; m<=M; m++) {
    for (int d=1; d<=D; d++) {
      int d1=d%10, d10=(d-d1)/10;
      if (d1>=2 && d10>=2 && d1*d10==m) {
        ans=ans+1;
      }
    }
  }
  cout << ans << endl;
}

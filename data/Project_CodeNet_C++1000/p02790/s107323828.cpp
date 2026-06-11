#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, ans;
  cin >> a >> b;
  if (a==1 && b==1) {
    ans=1;
  }
  else {
    if (a>=b) {
      ans=b;
      for (int i=1; i<a; i++) {
        ans=ans*10+b;
      }
    }
    else {
      ans=a;
      for (int j=1; j<b; j++) {
        ans=ans*10+a;
      }
    }
  }
  cout << ans << endl;
}
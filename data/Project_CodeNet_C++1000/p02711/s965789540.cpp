#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  string ans = "No";
  if (n/100==7) {
    ans = "Yes";
  }
  n -= n/100*100;
  if (n/10==7) {
    ans = "Yes";
  }
  n -= n/10*10;
  if (n==7) {
    ans = " Yes";
  }
  cout << ans << endl;
}
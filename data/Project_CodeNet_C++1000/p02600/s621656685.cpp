#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  int ans;

  cin >> x;

  if(x>=400 && x<600) {ans=8;}
  else if(x>=600 && x<800) {ans=7;}
  else if(x>=800 && x<1000) {ans=6;}
  else if(x>=1000 && x<1200) {ans=5;}
  else if(x>=1200 && x<1400) {ans=4;}
  else if(x>=1400 && x<1600) {ans=3;}
  else if(x>=1600 && x<1800) {ans=2;}
  else if(x>=1800 && x<2000) {ans=1;}

  cout << ans << endl;

  return 0;
}

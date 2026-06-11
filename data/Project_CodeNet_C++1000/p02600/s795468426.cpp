#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int X; cin >>X;
  int ans=0;
  if (X<600) {ans=8;}
  else if (X<800) {ans=7;}
  else if (X<1000) {ans=6;}
  else if (X<1200) {ans=5;}
  else if (X<1400) {ans=4;}
  else if (X<1600) {ans=3;}
  else if (X<1800) {ans=2;}
  else {ans=1;}
  cout <<ans <<endl;
  return 0;
}

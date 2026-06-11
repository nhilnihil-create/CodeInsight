#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  string ans;
  n -= n/100*100;
  n -= n/10*10;
  if (n==2 || n==4 || n==5 || n==7 || n==9) {
    ans = "hon";
  }
  if (n==0 || n==1 || n==6 || n==8) {
    ans = "pon";
  }
  if (n==3) {
    ans = "bon";
  }
  cout << ans << endl;
}
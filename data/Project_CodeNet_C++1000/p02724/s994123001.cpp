#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  
  long long ans;
  
  ans = (X/500)*1000 + ((X-(X/500)*500)/5)*5;
  
  cout << ans << endl;
  
}
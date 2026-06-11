#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if (c - (a - b) < 0) {
    cout << 0 << endl;
  } else {
    cout << c - (a - b) << endl;
  } 
}

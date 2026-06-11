#include <bits/stdc++.h>
#include <math.h>
#include<algorithm>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int m, d, s = 0;
  cin >> m >> d;
  rep(i, m){
    if(i < 3) continue;
    rep(j, d){
      if(j < 20) continue;
      else{
        int a = (j+1) / 10, b = (j+1) % 10;
        if(a * b == i+1 && a > 1 && b > 1) ++s;
      }
    }
  }
  cout << s << endl;
  return 0;
}
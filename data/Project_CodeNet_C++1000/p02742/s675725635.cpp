// #include <bits/stdc++.h>
#include <iostream>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repr(i,n) for (int i = 0; i < (f); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int main() {
  long h, w;
  cin >> h >> w;
  long ans;
  if(h == 1 || w == 1){
    cout << 1 << endl;
  }else{
    ans = h * w / 2;
    if ((h * w) % 2 == 1) ans++; 
    cout << ans << endl;
  }
  return 0;
}
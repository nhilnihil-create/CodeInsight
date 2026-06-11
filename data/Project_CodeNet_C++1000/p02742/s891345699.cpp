#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll h, w;
  cin >> h >> w;
  
  if (h==1 || w==1) cout << 1 << endl;
  else {
    if (h%2==1 && w%2==1) cout << h*w/2 + 1 << endl;
    else cout << h*w/2 << endl;
  }
}
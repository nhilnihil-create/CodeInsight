#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  rep(i,10000){
    int x=i*100;
    int y=i*105;
    if(x<=n&&y>=n){
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
    
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;
int main() {
  int x;cin>>x;
  while(1){
    int y = x;
    bool b = true;
    for(int i = 2; i < x; i++){if (y % i == 0) b = false;}
    if (b) {
      cout << y << endl;
      return 0;
    }
    x++;
  }
}
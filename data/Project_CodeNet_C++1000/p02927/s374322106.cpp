#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 1; i <= (int)(n); i++)

int main() {
  int m,d,ans = 0;
  cin >> m >> d;
  rep(i,m){
    rep(j,d){
      if(j/10 == 1 || j%10 == 1) continue;
      if((j/10)*(j%10) == i) ans++;
    }
  }
  cout<< ans << endl;
}
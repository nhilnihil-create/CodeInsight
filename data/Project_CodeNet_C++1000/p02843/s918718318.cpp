#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  ll x;
  cin >> x;
  rep(i,1000){
    if((x-100*i <= 5*i)&&(x-100*i >= 0)){
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
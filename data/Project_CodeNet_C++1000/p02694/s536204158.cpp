#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(void){
  ll x;
  cin >> x;
  ll m = 100;
  int cnt = 0;
  while(m < x){
    m += m / 100;
    cnt++;
  }
  cout << cnt << endl;
}

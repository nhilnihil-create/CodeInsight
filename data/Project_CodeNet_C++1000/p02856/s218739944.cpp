#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int m;
  cin >> m;
  ll d[m], c[m];
  ll sum = 0, digit = 0;
  rep(i,m) {
    cin >> d[i] >> c[i];
    digit += c[i];
    sum += c[i] * d[i];
  }
  cout << digit - 1 + (sum - 1)/9 << endl;
  return 0;
}
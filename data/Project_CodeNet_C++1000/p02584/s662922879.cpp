#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
  ll X, K, D;
  cin >> X >> K >> D;
  X = abs(X);
  ll cnt = X / D;
  if(cnt>K){
    cout << X - K * D << endl;
    return 0;
  }
  ll r = X % D;
  if ((K - cnt) % 2 == 0) cout << r << endl;
  else cout << min(abs(r+D), abs(r-D)) << endl;
  return 0;
}
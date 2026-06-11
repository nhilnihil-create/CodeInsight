#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
  ll n,k;
  cin >> n >> k;
  n = n - n/k*k;
  ll t = 2000000000000000000;
  while(true){
    n = abs(n-k);
    if(t < n){
      cout << t << endl;
      return 0;
    }
    t = n;
  }
}
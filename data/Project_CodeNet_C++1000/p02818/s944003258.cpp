#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  ll A, B;
  if(a+b<=k) {
    A=0;  B=0;
  }
  else if(a<=k) {
    A=0;  B=b-k+a;
  }
  else {
    A=a-k; B=b;
  }

  cout << A << " " << B << endl;
}
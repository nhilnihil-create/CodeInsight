#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  ll a=1;
  ll b=1;
  ll c=1;
  ll d=1;
  ll M = 1000000007;
  ll res = 0;
  rep(i,n){
    a*=10;
    b*=9;
    c*=9;
    d*=8;
    a%=M;
    b%=M;
    c%=M;
    d%=M;
    res=(a-b-c+d+M+M)%M;
  }
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  
  ll len = A+B;
  ll cnt = N/len*A;
  ll x = N%len;
  if(x<=A) cnt += x;
  else cnt += A;
  cout << cnt << endl;
  return 0;
}
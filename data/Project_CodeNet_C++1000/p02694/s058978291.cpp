#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll x;
  cin >> x;
  ll yokin = 100;
  ll cnt = 0;

  while(x > yokin){
    yokin = yokin + yokin/100;
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}
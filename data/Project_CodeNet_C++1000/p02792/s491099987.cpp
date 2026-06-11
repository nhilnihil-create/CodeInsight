#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int pre(int x) {
  if(x < 10) return x;
  else return pre(x / 10);
}

int main() {
  int n;
  cin >> n;
  int d[10][10];
  rep(p,10) rep(q,10) {
    d[p][q] = 0;
    rep(i,n) if(pre(i+1) == p && (i+1) % 10 == q) d[p][q]++;
  }
  int s = 0;
  rep(i,n) s += d[(i+1)%10][pre(i+1)];
  cout << s << endl;
  return 0;
}
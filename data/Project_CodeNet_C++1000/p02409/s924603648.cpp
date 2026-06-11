#include<cstdio>
#include<iostream>
using namespace std;

#define ll long long
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MD 1000000007

char sep[2] = {' ', '\n'};

int main() {
  int i, j, k, n, m, b, f, r, v;

  int room[4][3][10] = {};
  cin >> n;
  rep(i, n) {
    cin >> b >> f >> r >> v;
    b--, f--, r--;
    room[b][f][r] += v;
  }
  rep(i, 4) {
    rep(j, 3) rep(k, 10) {
      cout << " " << room[i][j][k];
      if (k == 9) cout << "\n";
    }
    if (i < 3) cout << "####################\n";
  }
  cout << flush;
  
  return 0;
}
  
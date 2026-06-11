#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int main() {
  int NUM[8], P[8], Q[8];
  int N,p,q;
  cin >> N;
  rep(i, N) cin >> P[i];
  rep(i, N) cin >> Q[i];
  rep(i, N) NUM[i] = i+1;
  int cnt = 0;
  do {
    cnt++;
    bool flag = true;
    rep(i, N) {
      if(P[i] != NUM[i]) flag = false;
    }
    if(flag) p = cnt;
  } while(next_permutation(NUM, NUM+N));
  cnt = 0;
  do {
    cnt++;
    bool flag = true;
    rep(i, N) {
      if(Q[i] != NUM[i]) {
        flag = false;
      }
    }
    if(flag) q = cnt;
  } while(next_permutation(NUM, NUM+N));
  cout << abs(p - q) << endl;
  return 0;
}

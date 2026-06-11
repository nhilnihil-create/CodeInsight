#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, K; cin >> N >> K;

  vector<int> h(N);
  rep( i, 0, N ) cin >> h.at(i);

  int Ans = 0;
  rep( i, 0, N ) {
    if ( K<=h.at(i) ) {Ans++;
    }
  }
  cout << Ans << endl;
}

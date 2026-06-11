#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N; cin >> N;
  vector<float> A(N);
  rep( i, 0, N ) cin >> A.at(i);

  float Ans = 0.0;
  rep( i, 0, N ) {
    Ans += 1.0 / A.at(i);
  }

  Ans =  1.0 / Ans;
  cout << Ans << endl;
}

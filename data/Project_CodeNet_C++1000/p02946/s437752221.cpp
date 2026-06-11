#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int K, X; cin >> K >> X;

  rep( i, X-K+1, X+K ) cout << i << ' ';
  cout << endl;
}

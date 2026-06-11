#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

int main() {
  int N, M; cin >> N >> M;

  rep(i, (M+1)/2)
    cout << N - i << " " << N - (M-i) << endl;
  rep(i, M/2)
    cout << i+1 << " " << M-i << endl;
  return 0;
}

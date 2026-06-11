#include <iostream>
using namespace std;
long N, A[300010], B[300010];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; ++i) {
    long a; cin >> a; --a;
    ++A[a]; // cnt
    ++B[A[a]]; // cnt of cnt
  }
  
  for(int i = 1; i < N; ++i) B[i+1] += B[i];

  for(int i = 1; i <= N; ++i) {
    long ok = 0, ng = N+1;
    while(ng - ok > 1) {
      long mid = (ok + ng) >> 1;
      if(B[mid] >= mid * i) ok = mid;
      else ng = mid;
    }
    cout << ok << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ll long long
#define INF 999999999
using namespace std;
int main() {
  int N,M;
  std::cin >> N >> M;
  if (N%2) {
    for (int i = 1; i <= M; i++) {
      std::cout << i << " " << N-i+1 << '\n';
    }
  }
  else{
    for (int i = 1; i <= M; i++) {
      if (i <= (double)N/4) {
        std::cout << i << " " <<N-i+1 << '\n';
      }
      else{
        std::cout << i << " " << N-i << '\n';
      }
    }
  }
}

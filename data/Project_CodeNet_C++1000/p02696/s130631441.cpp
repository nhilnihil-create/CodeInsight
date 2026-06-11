#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t A,B,N;
  cin>>A>>B>>N;
  auto k=min(B-1,N);
  cout<<floor(A*k/B)-A*floor(k/B);
}

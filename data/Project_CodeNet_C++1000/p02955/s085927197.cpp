#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

vector<int> divisors(int n) {
  vector<int> ret;
  for(int i=1; i*i<=n; ++i) {
    if(n % i != 0) continue;
    ret.push_back(i);
    if(i * i != n) {
      ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end(), greater<int>());
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N) { cin >> A[i]; }
  for(const auto& d : divisors(accumulate(A.begin(), A.end(), 0))) {
    vector<int> b(N);
    REP(i, N) { b[i] = A[i] % d; }
    sort(b.begin(), b.end());
    int k = N - accumulate(b.begin(), b.end(), 0) / d;
    int sum = accumulate(b.begin(), b.begin() + k, 0);
    if(sum <= K) {
      cout << d << endl;
      break;
    }
  }
}
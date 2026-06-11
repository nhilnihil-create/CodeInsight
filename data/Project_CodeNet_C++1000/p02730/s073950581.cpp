#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  rep(i,N) {
    if (S[i] != S[N-1-i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < (N-1)/2; ++i) {
    if (S[i] != S[(N-1)/2 - 1 - i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = (N+1)/2; i < N; ++i) {
    if (S[i] != S[N - 1 - i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
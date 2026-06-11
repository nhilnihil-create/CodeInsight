#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int N, K;
int A[200000];

// 回数k以内で長さlにカットできるかどうか
bool can_cut(int l) {
  int cnt = 0;
  rep(i, N) {
    cnt += A[i] / l;
    if (A[i] % l == 0) cnt--;
  }
  return cnt <= K;
}

int main() {
  cin >> N >> K;
  rep(i, N) cin >> A[i];
  
  // binary search
  int lb = 0, ub = 1e9;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (can_cut(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  
  cout << ub;
}
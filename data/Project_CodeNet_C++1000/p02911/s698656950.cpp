#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,K,Q;
  cin >> N >> K >> Q;
  vector<int>cnt(N,K-Q);
  while(Q--) {
    int A;cin >> A;A--;
    cnt[A]++;
  }
  for(int i = 0; i < N; i++) {
    if(cnt[i] <= 0) {
      cout << "No" << endl;
    }
    else {
      cout << "Yes" << endl;
    }
  }
}
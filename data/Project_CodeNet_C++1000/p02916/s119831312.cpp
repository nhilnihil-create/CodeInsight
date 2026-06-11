#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  int total = 0;
  std::vector<int> A(n);
  std::vector<int> B(n);
  std::vector<int> C(n);
  rep(i,n) {
    int x;
    cin >> x;
    x--;
    A.at(i) = x;
  }
  rep(i,n) {
    cin >> B.at(i);
    total += B.at(i);
  }
  rep(i,n-1) cin >> C.at(i);

  rep(i,n-1) {
    if (A.at(i)+1 == A.at(i+1)) {
      total += C.at(A.at(i));
    }
  }
  cout << total << endl;
}

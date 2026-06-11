#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll A, B, C, N;
  cin >> A >> B >> C >> N;
  if(N <= A) {
    cout << N;
  }
  else if(N <= A + B) {
    cout << A;
  }
  else {
    cout << A - (N - A - B) << endl;
  }
}
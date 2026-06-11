#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, A, B, ans;
  cin >> N >> A >> B;
  int64_t mod = N % (A + B);
  cout << N / (A + B) * A + (A > mod ? mod : A) << endl;
}
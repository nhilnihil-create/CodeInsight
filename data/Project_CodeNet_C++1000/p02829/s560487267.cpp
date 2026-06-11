#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A[2];
  cin >> A[0] >> A[1];
  sort(A,A+2);
  if (A[0] == 1 && A[1] == 2) {
    cout << 3 << endl;
  } else if (A[0] == 1 && A[1] == 3) {
    cout << 2 << endl;
  } else {
    cout << 1 << endl;
  }
  return 0;
}
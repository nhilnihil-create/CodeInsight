#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  int A[N];
  rep (i, N) {
    cin >> A[i];
    if (A[i] % 2 == 0 && A[i] % 3 != 0 && A[i] % 5 != 0) {
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;

  return 0;
}
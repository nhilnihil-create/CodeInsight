#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);

int main() {
  int N, D;
  cin >> N >> D;
  int range = D * 2 + 1;
  if(N % range == 0) cout << N / range << endl;
  else cout << N / range + 1 << endl;
}

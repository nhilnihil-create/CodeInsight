#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  cout << (1000 - (n % 1000)) % 1000 << endl;
  return 0;
}
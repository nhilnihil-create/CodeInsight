#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  if (N / 100 == 7 || (N % 100) / 10 == 7 || N % 10 == 7)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

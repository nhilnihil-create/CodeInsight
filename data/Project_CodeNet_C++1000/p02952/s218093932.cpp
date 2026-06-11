#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  int count = 0;

  rep2(i, n) if (to_string(i).length() % 2 == 1) count++;

  cout << count << endl;
  return 0;
}

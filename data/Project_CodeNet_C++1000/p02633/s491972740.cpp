#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int k = 1;
  while (k * n % 360 != 0) k++;
  cout << k << "\n";

  return 0;
}
//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, t;
  cin >> n >> x >> t;
  cout << (n + x - 1) / x * t << '\n';
  return 0;
}

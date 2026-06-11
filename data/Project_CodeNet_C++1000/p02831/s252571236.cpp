#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  ll a, b;
  cin >> a >> b;

  cout << a * b / __gcd(a, b) << endl;
}
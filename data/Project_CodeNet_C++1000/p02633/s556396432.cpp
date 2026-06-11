#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  double X;
  cin >> X;
  cout << (360 / gcd(X, 360LL)) << endl;
  return 0;
}
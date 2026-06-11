#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  int minA = 1e9;
  int minB = 1e9;
  for (int i = 0; i < A; ++i) cin >> a[i];
  for (int i = 0; i < A; ++i) minA = min(minA, a[i]);
  for (int i = 0; i < B; ++i) cin >> b[i];
  for (int i = 0; i < B; ++i) minB = min(minB, b[i]);

  int result = minA + minB;
  for (int i = 0; i < M; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    result = min(result, a[x] + b[y] - c);
  }
  cout << result << endl;

  return 0;
}

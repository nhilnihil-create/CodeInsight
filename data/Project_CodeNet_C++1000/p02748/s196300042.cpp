#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  int A, B, M;
  cin >> A >> B >> M;

  vector<int> a(A);
  vector<int> b(B);

  for (int i = 0; i < A; ++i)
    cin >> a[i];
  for (int i = 0; i < B; ++i)
    cin >> b[i];

  int min_price = 1000000;

  for (int i = 0; i < M; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    min_price = min(min_price, a[x - 1] + b[y - 1] - c);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  min_price = min(a[0] + b[0], min_price);

  cout << min_price << endl;

  return 0;
}
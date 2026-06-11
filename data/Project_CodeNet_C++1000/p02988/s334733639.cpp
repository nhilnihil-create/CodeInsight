#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  int cnt = 0;
  for (int i = 1; i < n - 1; ++i) {
    int a = vec[i - 1];
    int b = vec[i];
    int c = vec[i + 1];

    bool det1 = a < b && b <= c;
    bool det2 = a == b && a < c;
    bool det3 = c < b && b <= a;
    bool det4 = c == b && c < a;
    cnt += det1 || det2 || det3 || det4;
  }
  cout << cnt << endl;
}
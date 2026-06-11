#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int N, a;
  bool cond{1};
  cin >> N;
  map<int, int> m;
  vector<int> v;
  if (N % 3) {
    while (cin >> a) {
      if (a) {
        cond = 0;
        break;
      }
    }
  } else {
    while (cin >> a) {
      ++m[a];
      if (m[a] == N / 3) {
        v.push_back(a);
        m[a] = 0;
      }
    }
    cond = v.size() == 3 && !(v[0] ^ v[1] ^ v[2]);
  }

  cout << (cond ? "Yes" : "No") << endl;
}

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec) {
    char c;
    cin >> c;
    v = c - '0';
  }

  set<int> s1;
  set<int> s2;
  set<int> s3;
  s1.insert(vec[0]);
  s1.insert(vec[1]);
  s2.insert(vec[0] * 10 + vec[1]);

  for (int i = 2; i < n; ++i) {
    for (auto &v2 : s2)
      s3.insert(v2 * 10 + vec[i]);
    for (auto &v1 : s1)
      s2.insert(v1 * 10 + vec[i]);
    s1.insert(vec[i]);
  }
  cout << static_cast<int>(s3.size()) << endl;
}
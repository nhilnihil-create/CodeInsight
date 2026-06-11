#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> vec(3);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());
  cout << vec[0] + vec[1] << endl;
}
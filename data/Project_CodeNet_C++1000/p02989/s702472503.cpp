#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  sort(vec.begin(), vec.end());

  cout << vec[n/2] - vec[n/2-1] << endl;
}
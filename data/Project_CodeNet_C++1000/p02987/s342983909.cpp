#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<char> vec(4);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());
  if (vec[0] == vec[1] && vec[2] == vec[3] && vec[1] != vec[2])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
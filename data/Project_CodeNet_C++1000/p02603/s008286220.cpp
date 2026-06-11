#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (auto &v : vec)
    cin >> v;

  long long money = 1000;
  for (int i = 1; i < n; ++i)
    if (0 < vec[i] - vec[i - 1])
      money += money / vec[i-1] * (vec[i] - vec[i-1]);
  cout << money << endl;
}

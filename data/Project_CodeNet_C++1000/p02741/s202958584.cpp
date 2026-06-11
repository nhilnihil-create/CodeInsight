#include <bits/stdc++.h>
using namespace std;

int main() {
  int index;
  cin >> index;
  vector<int> numList = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  cout << numList.at(index - 1) << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
 vector<int> arr;
  for (int i = 0; i < 5; ++i) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  for (int i = 0; i < 5; ++i) {
    if (arr[i] == 0) {
      cout << i+1 << endl;
      break;
    }
  }
}

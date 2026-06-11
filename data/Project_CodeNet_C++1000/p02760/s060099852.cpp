#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<vector<int>> a(3, vector<int>(3));
  vector<vector<bool>> c(3, vector<bool>(3, false));
  cin >> a.at(0).at(0) >> a.at(0).at(1) >> a.at(0).at(2);
  cin >> a.at(1).at(0) >> a.at(1).at(1) >> a.at(1).at(2);
  cin >> a.at(2).at(0) >> a.at(2).at(1) >> a.at(2).at(2);
  int n; 
  cin >> n;
  for (int i = 0; i < n; ++i)  {
    int b;
    cin >> b;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (a.at(i).at(j) == b) {
          c.at(i).at(j) = true;
        }
      }
    }
  }

  bool judge = false;
  for (int i = 0; i < 3; ++i) {
    if (c.at(i).at(0) && c.at(i).at(1) && c.at(i).at(2)) {
      judge = true;
      break;
    }
    if (c.at(0).at(i) && c.at(1).at(i) && c.at(2).at(i)) {
      judge = true;
      break;
    }
  }
  if (c.at(0).at(0) && c.at(1).at(1) && c.at(2).at(2)) {
    judge = true;
  }
  if (c.at(0).at(2) && c.at(1).at(1) && c.at(2).at(0)) {
    judge = true;
  }
  if (judge) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}

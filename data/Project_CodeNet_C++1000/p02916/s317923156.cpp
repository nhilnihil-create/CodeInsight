#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ai(n);
  vector<int> bi(n);
  vector<int> ci(n-1);
  for (int i = 0; i < n; i++) {
    cin >> ai.at(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> bi.at(i);
  }
  for (int i = 0; i < n-1; i++) {
    cin >> ci.at(i);
  }
  
  int manzoku = 0;
  int before_num = -1;
  for (int i = 0; i < n; i++) {
    int select_num = ai.at(i);
    manzoku += bi.at(select_num-1);
    if (before_num+1 == select_num) {
      manzoku += ci.at(before_num-1);
    }
    before_num = select_num;
  }
  cout << manzoku << endl;
}
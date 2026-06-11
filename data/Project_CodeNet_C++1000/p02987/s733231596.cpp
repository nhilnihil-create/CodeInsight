#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int size = S.size();
  map<char, int> count;
  for (int i = 0; i < size; i++) {
  	char tmp= S[i];
    count[tmp] += 1;
  }

  bool flag = true;
  for (auto p : count) {
    auto value = p.second;
    if (value != 2) {
      flag = false;
      break;
    }
  }
  if (flag) {
  	cout << "Yes" << endl;
  } else {
  	cout << "No" << endl;
  }
}
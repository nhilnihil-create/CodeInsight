#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  for (int i = 0; i < S.size(); ++i) {
    if (i % 2 == 0) {
      if (S[i] == 'L') {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (S[i] == 'R') {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}

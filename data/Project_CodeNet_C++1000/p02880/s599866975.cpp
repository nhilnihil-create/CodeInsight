#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int X;
  cin >> X;
  int c = 0;
  rep(i, 9) {
    rep(j, 9) {
      if(vec.at(i) * vec.at(j) == X) {
        c++;
      }
    }
  }
  if(c == 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}

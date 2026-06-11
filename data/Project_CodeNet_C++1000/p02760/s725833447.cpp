#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  std::vector<std::vector<int>> vec(3,std::vector<int>(3));
  rep(i,3) {
    rep(j,3) {
      cin >> vec.at(i).at(j);
    }
  }
  int n;
  cin >> n;
  std::vector<int> b(n);
  rep(i,n) {
    cin >> b.at(i);
  }
  rep(i,3) {
    rep(j,3) {
      rep(k,n) {
        if(vec.at(i).at(j) == b.at(k)) {
          vec.at(i).at(j) = 0;
        }
      }
    }
  }
  rep(i,3) {
    if ((vec.at(i).at(0) == 0 && vec.at(i).at(1) == 0 && vec.at(i).at(2) == 0) ||
    (vec.at(0).at(i) == 0 && vec.at(1).at(i) == 0 && vec.at(2).at(i) == 0)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if ((vec.at(0).at(0) == 0 && vec.at(1).at(1) == 0 && vec.at(2).at(2) == 0) ||
  (vec.at(0).at(2) == 0 && vec.at(1).at(1) == 0 && vec.at(2).at(0) == 0)) {
    cout << "Yes" << endl;
    return 0;
  } else {
    cout << "No" << endl;
  }
}

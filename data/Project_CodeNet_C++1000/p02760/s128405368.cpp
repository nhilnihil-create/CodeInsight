#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<vector<int>> a(3, vector<int>(3));
  rep(i, 3) rep(j, 3) {
    cin >> a.at(i).at(j);
  }
  int n;
  cin >> n;
  vector<vector<int>> cmp(3, vector<int>(3));
  rep(i, n) {
    int b;
    cin >> b;
    rep(j, 3) rep(k, 3) {
      if(b == a.at(j).at(k)) cmp.at(j).at(k) = 1;
    }
  }
  bool flag = false;
  int tmp = 0;
  int tmp_4 = 0;
  rep(i, 3) {
    if(cmp.at(i).at(i) == 1) tmp++;
    if(cmp.at(i).at(2-i) == 1) tmp_4++;
    if(tmp == 3) flag = true;
    if(tmp_4 == 3) flag = true;
    int tmp_2 = 0;
    int tmp_3 = 0;
    rep(j, 3) {
      if(cmp.at(i).at(j) == 1) tmp_2++;
      if(cmp.at(j).at(i) == 1) tmp_3++;
      if(tmp_2 == 3) flag = true;
      if(tmp_3 == 3) flag = true;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
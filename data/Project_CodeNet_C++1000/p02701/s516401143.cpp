#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N;
  cin >> N;
  set<string> goods;
  rep(i,N) {
    string s;
    cin >> s;
    goods.insert(s);
  }
  cout << goods.size() << endl;

  return 0;
}
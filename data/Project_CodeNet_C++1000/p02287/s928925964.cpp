#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i < (int)(n + 1); i++)
using namespace std;

int H;
vector<int> v;

int main() {
  cin >> H;
  v.resize(H + 1);
  rep1(i, H) {
    cin >> v[i];
  }
  rep1(i, H) {
    cout << "node " << i << ": ";
    cout << "key = " << v[i] << ", ";
    if (i != 1) cout << "parent key = " << v[i / 2] << ", ";
    if (2 * i <= H) cout << "left key = " << v[2 * i] << ", ";
    if (2 * i + 1 <= H) cout << "right key = " << v[2 * i + 1] << ", ";
    cout << endl;
  }
  return 0;
}


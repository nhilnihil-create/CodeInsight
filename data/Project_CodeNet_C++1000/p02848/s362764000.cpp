#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N; 
  string S;
  cin >> N >> S;
  for (auto i : S) {
    int t = int(i) + N;
    if (t > 90) t -= 26;
    cout << char(t);
  }
  cout << endl;
  return 0;
}
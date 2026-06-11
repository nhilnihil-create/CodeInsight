#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  std::vector<int> v(3);
  rep(i,3) cin >> v.at(i);
  sort(v.begin(), v.end());
  cout << v.at(0) + v.at(1) << endl;
}

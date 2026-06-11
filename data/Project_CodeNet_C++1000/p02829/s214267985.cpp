#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;

int main() {
  int a,b;
  cin >> a >> b;
  std::vector<bool> vec(3,true);
  vec.at(a-1) = false;
  vec.at(b-1) = false;
  for (int i = 0; i < 3; i++) {
    if (vec.at(i)) cout << i+1 << endl;
  }

}

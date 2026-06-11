#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  int n;
  cin >> n;
  std::vector<int> vec;
  rep(i,n) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      vec.push_back(x);
    }
  }
  bool ok = true;
  for (int i : vec) {
    if (i % 3 != 0 && i % 5 != 0) {
      ok = false;
    }
  }
  if (ok) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}

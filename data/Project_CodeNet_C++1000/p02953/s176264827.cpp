#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n);
  rep(i,n) cin >> vec.at(i);
  bool ok = true;
  int num = 0;
  rep(i,n-1) {
    num = max(num, vec.at(i)-1);
    if (vec.at(i)-1 > vec.at(i+1)) ok = false;
    else if (num > vec.at(i+1)) ok = false;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}

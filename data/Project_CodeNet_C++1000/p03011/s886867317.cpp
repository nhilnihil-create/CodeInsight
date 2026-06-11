#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int p,q,r;
  cin >> p >> q >> r;
  vector<int> a={p,q,r};
  sort(a.begin(),a.end());
  cout << a.at(0)+a.at(1) << endl;
}


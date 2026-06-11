#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<double> vec(n);
  rep(i,n) cin >> vec.at(i);
  double total = 0.0;
  int i = 0;
  while (vec.size() != 1) {
    sort(vec.begin(), vec.end());
    total = (vec.at(i) + vec.at(i+1)) / 2.0;
    reverse(vec.begin(), vec.end());
    vec.pop_back();
    vec.pop_back();
    vec.push_back(total);
  }
  cout << vec.at(0) << endl;
}

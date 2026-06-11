#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1'000'000'000;

int main() {
  int k,n;
  cin >> k >> n;
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  vec.push_back(vec.at(0) + k);
  int maxLength = 0;
  int total = 0;
  for (int i = 0; i<n; i++) {
    total += abs(vec.at(i) - vec.at(i+1));
    maxLength = max(maxLength, abs(vec.at(i) - vec.at(i+1)));
  }
  cout << total - maxLength << endl;
}

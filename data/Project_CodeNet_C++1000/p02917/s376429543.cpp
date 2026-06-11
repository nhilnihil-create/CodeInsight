#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n-1);
  rep(i,n-1) cin >> vec.at(i);
  vec.push_back(1e5);
  int total = vec.at(0);
  rep(i,n-1) {
    total += min(vec.at(i), vec.at(i+1));
  }
  cout << total << endl;

}

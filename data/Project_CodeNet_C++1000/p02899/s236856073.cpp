#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n);
  std::vector<int> d(n);
  rep(i,n) {
    int x;
    cin >> x;
    x--;
    vec.at(i) = x;
    d.at(i) = x;
  }
  sort(d.begin(), d.end());
  for (auto i : d) {
    auto num = find(vec.begin(), vec.end(), i);
    // イテレータだと1,2,3となってしまう
    const int wanted_index = std::distance(vec.begin(), num);
    cout << wanted_index+1 << " ";
  }
  cout << endl;

}

#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  std::vector<int> vec(n), d(n);
  rep(i,n) {
    int x;
    cin >> x;
    vec.at(i) = x;
    d.at(i) = x;
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());

  rep(i,n) {
    if (vec.at(i) == d.at(0)) {
      cout << d.at(1) << endl;
    } else {
      cout << d.at(0) << endl;
    }
  }
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main() {
  ll n,k;
  cin >> n >> k;
  std::vector<int> vec(n);
  rep(i,n) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  ll total = 0;
  rep(i,k) {
    total += vec.at(i);
  }
  cout << total << endl;
}

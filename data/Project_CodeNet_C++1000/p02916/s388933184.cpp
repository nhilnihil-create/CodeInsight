#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
  }
  rep(i, n) cin >> b.at(i);
  rep(i, n) cin >> c.at(i);
  int sum = 0;
  rep(i, n) {
    sum += b.at(a.at(i));
    if(a[i] == a[i-1] + 1 && i > 0) {
      sum += c[a[i-1]];
    }
  }
  cout << sum << endl;
}
    
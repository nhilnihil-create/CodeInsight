#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  int A, B, M, ans = 200000;
  cin >>A>>B>>M;
  vector<int>a(A);
  vector<int>b(B);
  vector<int>c(M);
  vector<int>x(M);
  vector<int>y(M);
  rep(i, A) {
    cin >> a.at(i);
  }
  rep(i, B) {
    cin >> b.at(i);
  }
  rep(i, M) {
    cin >> x.at(i) >> y.at(i) >> c.at(i);
  }
  rep(i, M) {
    if (ans > a.at(x.at(i)-1) + b.at(y.at(i)-1) - c.at(i)) {
      ans = a.at(x.at(i)-1) + b.at(y.at(i)-1) - c.at(i);
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (ans > a.at(0) + b.at(0)) {
    ans = a.at(0) + b.at(0);
  }
  cout << ans;
}

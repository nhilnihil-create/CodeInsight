
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main() {
  double n,m,sum = 0;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    sum += 1 / a[i];
  }
  sum = 1 / sum;
  cout << sum << '\n';
  return 0;
}
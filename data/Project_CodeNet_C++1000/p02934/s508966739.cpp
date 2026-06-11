#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  int n; cin >> n;
  vector<double> a(n);
  for (auto && i : a) {
    double tmp;
    cin >> tmp;
    tmp = 1 / tmp;
    i = tmp;
  }
  double sum = 0;
  for (auto && i : a) {
    sum += i;
  }
  cout << fixed << setprecision(10) << 1 /sum << endl;

}
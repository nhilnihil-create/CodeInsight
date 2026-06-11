#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int n;
  cin >> n;
  vector<long double> a(n);
  rep(i,n) cin >> a[i];
  long double sum=0;
  rep(i,n){
    sum += 1/a[i];
  }
  cout << fixed << setprecision(10);
  cout << 1/sum << endl;
}
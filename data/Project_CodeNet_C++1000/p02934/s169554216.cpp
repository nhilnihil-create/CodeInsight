#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<double> a(n);
  rep(i, n) cin >> a[i];
  double sum = 0;
  rep(i, n) {
    sum+= 1/a[i];
  }
  cout << 1/sum << endl;
  return 0;
}
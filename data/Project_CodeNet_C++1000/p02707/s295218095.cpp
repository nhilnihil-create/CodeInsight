#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    a--;
    x[a]++;
  }
  for (int i = 0; i < n; i++) cout << x[i] << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> p(n,k-q);
  rep(i,q) {
    int a;
    cin >> a;
    a--;
    p[a]++;
  }
  rep(i,n) {
    puts(p[i] > 0? "Yes":"No");
  }
  return 0;
}

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int>a(n, 0);
  rep(i, q) {
    int j;
    cin >> j;
    a[j-1]++;
  }
  rep(i, n) {
    if(q-a[i] < k) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
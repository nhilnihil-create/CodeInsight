#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  rep(i, n){
    int x, y; cin >> x >> y;
    a[i] = x + y;
    b[i] = x - y;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << max(abs(a[0] - a[n - 1]), abs(b[0] - b[n - 1])) << endl;
  return 0;
}

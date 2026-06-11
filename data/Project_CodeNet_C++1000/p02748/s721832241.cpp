#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
  rep(i, M){
    int x1, y1, c1;
    cin >> x1 >> y1 >> c1;
    x1--; y1--;
    ans = min(ans, a[x1] + b[y1] - c1);
  }
  cout << ans << endl;
  return 0;
}

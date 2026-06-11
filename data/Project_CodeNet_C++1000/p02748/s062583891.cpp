#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,int>;
using T = tuple<string,int,int>;

int main(){
  int A,B,M; cin >> A >> B >> M;
  vector<int> a(A), b(B);
  for(int i = 0; i < A; i++) cin >> a[i];
  for(int i = 0; i < B; i++) cin >> b[i];
  int amn = *min_element(a.begin(), a.end());
  int bmn = *min_element(b.begin(), b.end());
  ll ans = amn + bmn;
  for(int i = 0; i < M; i++){
    int x,y,c; cin >> x >> y >> c;
    x--; y--;
    ll temp = a[x] + b[y] - c;
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}

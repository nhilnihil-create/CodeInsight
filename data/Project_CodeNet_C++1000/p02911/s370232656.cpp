#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, K, Q;
  cin >> N >> K >> Q;
  vector <int> point(N, K - Q);
  rep(i,Q){
    int a;
    cin >> a;
    a --;  //0-indexedに直す
    point[a] ++;
  }
  rep(i,N){
    if (point[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}

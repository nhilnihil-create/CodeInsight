#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <P> p(N);
  rep(i,N){
    cin >> p[i].first;
    p[i].second = i + 1;  //1-indexedで出席番号を管理
  }
  sort(all(p));
  rep(i,N) cout << p[i].second  << " ";

  return 0;
}

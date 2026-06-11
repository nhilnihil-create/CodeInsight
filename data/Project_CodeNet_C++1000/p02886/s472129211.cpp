#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> d(N);
  rep(i,N) cin >> d.at(i);

  int ans = 0;
  for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
      ans += d.at(i) * d.at(j);
    }
  }
  cout << ans << endl;
}

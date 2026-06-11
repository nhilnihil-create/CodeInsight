#include <bits/stdc++.h>
using namespace std;
using lint = long long;
typedef pair<int, int> P;

signed main(){
  lint N; cin >> N;
  vector<lint> x(N), y(N);
  for(lint i = 0; i < N; i++) cin >> x[i] >> y[i];
  map<P, lint> MAP;
  for(lint i = 0; i < N; i++){
    for(lint j = 0; j < N; j++){
      if(i != j) MAP[P(x[i] - x[j], y[i] - y[j])]++;
    }
  }
  lint ans = 0;
  for(auto value : MAP) ans = max(ans, value.second);
  cout << N - ans << endl;
}
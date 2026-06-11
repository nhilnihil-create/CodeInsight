#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  int N; cin >> N;
  vector<int> d(N); rep(i, N) cin >> d.at(i);
  int ans = 0;
  rep(i, N-1){
    for(int j = i+1; j < N; j++){
      ans += d.at(i)*d.at(j);
    }
  }
  cout << ans << endl;
  return 0;
}
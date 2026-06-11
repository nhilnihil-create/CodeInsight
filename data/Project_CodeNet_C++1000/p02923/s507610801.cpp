#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> H(N);
  cin >> H.at(0);
  int ans = 0, tmp = 0;
  for (int i = 1; i < N; i++){
    cin >> H.at(i);
    if (H.at(i - 1) >= H.at(i)) tmp++;
    if (H.at(i - 1) < H.at(i) || i == N - 1){
      ans = max(ans, tmp);
      tmp = 0;
    }
    //cout << ans << " " << tmp << endl;
  }
  cout << ans << endl;
  return 0;
}
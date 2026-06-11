#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, K;
  cin >> N >> K;
  vector<long> data(N);
  for(int i = 0; i < N; i++)cin >> data.at(i);
  vector<pair<long, long>> sub(N);
  long ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(j < i){
        if(data.at(j) < data.at(i))sub.at(i).first++;
      } else if(j > i){
        if(data.at(j) < data.at(i))sub.at(i).second++;
      }
    }
    ans += sub.at(i).first * ((K - 1) * K / 2 % 1000000007);
    ans %= 1000000007;
    ans += sub.at(i).second *(K * (K + 1) / 2 % 1000000007);
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
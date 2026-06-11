#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<pair<string, long>> data(N);
  for(int i = 0; i < N; i++){
    cin >> data.at(i).first >> data.at(i).second;
  }
  string X;
  cin >> X;
  long ans = 0, flag = 0;
  for(int i = 0; i < N; i++){
    if(flag == 1)ans += data.at(i).second;
    if(data.at(i).first == X)flag = 1;
  }
  cout << ans << endl;
  return 0;
}

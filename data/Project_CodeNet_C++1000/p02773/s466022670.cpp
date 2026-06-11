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
  map<string, int> memo;
  rep(i,N){
    string S;
    cin >> S;
    memo[S] ++;
  }
  int mx = 0;
  for (auto p : memo) mx = max(mx, p.second);  //最大値をmxに入れる
  for (auto p : memo){
    if (p.second != mx) continue;
    cout << p.first << endl;
  }
  return 0;
}

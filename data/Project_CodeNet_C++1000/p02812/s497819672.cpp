#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 0; i <= N - 3; i++){
    if (S.at(i) == 'A' && S.at(i + 1) == 'B' && S.at(i + 2) == 'C') ans++;
  }
  cout << ans << endl;
}

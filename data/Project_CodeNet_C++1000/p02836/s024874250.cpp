#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string S;
  cin >> S;

  int ans = 0;
  int N = S.size();
  rep(i,N){
    if (S.at(i) != S.at(N - 1 - i)){
      ans++;
      S.at(i) = S.at(N - 1 - i);
    }
  }
  cout << ans << endl;
}

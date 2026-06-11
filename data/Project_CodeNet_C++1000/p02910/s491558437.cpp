#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string S;
  cin >> S;

  int N = S.size();
  string ans = "Yes";
  rep(i,N){
    if ((i % 2 == 0 && S.at(i) == 'L') || (i % 2 == 1 && S.at(i) == 'R')){
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}

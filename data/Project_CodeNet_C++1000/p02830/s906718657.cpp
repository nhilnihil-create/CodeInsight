#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  string S, T;
  cin >> N >> S >> T;

  rep(i,N) cout << S.at(i) << T.at(i);
  cout << endl;
}

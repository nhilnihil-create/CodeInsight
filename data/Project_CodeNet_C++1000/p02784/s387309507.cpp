#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int H, N;
  cin >> H >> N;
  vector <int> A(N);
  rep(i,N) cin >> A.at(i);

  int sum = accumulate(A.begin(), A.end(), 0);
  if (sum >= H) cout << "Yes" << endl;
  else cout << "No" << endl;

}

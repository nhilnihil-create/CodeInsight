#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  vector<double> vec(N);
  for (int i = 0; i < N; i++) cin >> vec.at(i);

  cout << fixed << setprecision(6) << endl;

  double under = 0;

  for (int i = 0; i < N; i++){
    under += 1 / vec.at(i);
  }

  double ans = 1 / under;

  cout << ans << endl;
}
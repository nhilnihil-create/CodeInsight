#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, D, A;
  cin >> N >> D >> A;
  vector<pair<int, int>> M(N);
  for (int i = 0; i < N; i++){
    int X, H;
    cin >> X >> H;
    M[i] = make_pair(X, (H + A - 1) / A);
  }
  sort(M.begin(), M.end());
  vector<int> imos(N + 1, 0);
  long long ans = 0;
  for (int i = 0; i < N; i++){
    if (i > 0){
      imos[i] += imos[i - 1];
    }
    M[i].second -= imos[i];
    if (M[i].second > 0){
      ans += M[i].second;
      auto itr = upper_bound(M.begin(), M.end(), make_pair(M[i].first + D * 2 + 1, -1));
      imos[i] += M[i].second;
      imos[itr - M.begin()] -= M[i].second;
    }
  }
  cout << ans << endl;
}
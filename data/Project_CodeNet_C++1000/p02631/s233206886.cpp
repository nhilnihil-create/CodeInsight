#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, total, count = 0, ans;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  total = a.at(0);
  for (int i = 1; i < N; i++){
    total = total^a.at(i);
  }
  for (int i = 0; i < N; i++){
    ans = total^a.at(i);
    cout << ans << ' ';
  }
  cout <<  endl;
}

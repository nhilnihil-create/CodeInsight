#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans=0;
  cin >> N;
  vector<int> list(N);
  
  for (int i = 0; i < N; i++) cin >> list.at(i);
  for (int j = 1; j < N-1; j++) {
    if (list.at(j-1) < list.at(j) && list.at(j) < list.at(j+1)) ans++;
    if (list.at(j+1) < list.at(j) && list.at(j) < list.at(j-1)) ans++;
  }
  
  cout << ans << endl;
}
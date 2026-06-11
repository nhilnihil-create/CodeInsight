#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, ans=0, cnt=1;
  cin >> N >> X;
  vector<int> list(N);
  
  for (int i = 0; i < N; i++) cin >> list.at(i);
  for (int j = 0; j < N; j++) {
    ans = ans + list.at(j);
    if (ans <= X) cnt++;
  }
  
  cout << cnt << endl;
}
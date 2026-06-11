#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    vector<int> num = {i/100, (i%100)/10, i%10};
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if ('0'+num[cnt] == S[j]) cnt++;
      if (cnt == 3) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}

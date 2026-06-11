#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  string S, T; cin >> S >> T;
  int s = S.size(), t = T.size();
  int count = 0;
  for(int i = 0; i <= s - t; i++) {
    int cnt = 0;
    for(int j = 0; j < t; j++) {
      if(S.at(i + j) == T.at(j)) cnt++;
    }
    if(count < cnt) count = cnt;
  }
  cout << t - count << endl;
}

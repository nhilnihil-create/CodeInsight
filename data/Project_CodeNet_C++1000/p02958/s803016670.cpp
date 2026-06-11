#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> p(N);
  string ans = "YES";

  for (int i = 0; i < N; i++) {
    cin >> p.at(i);
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (p.at(i) != i + 1) {
        count++;
    }
  }
  if (count < 3) {
    ans = "YES";
  } else {
    ans = "NO";
  }
  cout << ans << endl;
  
  
  
}

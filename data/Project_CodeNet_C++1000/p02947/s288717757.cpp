#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> data(N);
  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    data.at(i) = s;
  }
  sort(data.begin(), data.end());
  vector<int64_t> count;
  count.push_back(1);
  for(int i = 1; i < N; i++) {
    if(data.at(i) == data.at(i - 1)) {
      count.at(count.size() - 1)++;
    }
    else {
      count.push_back(1);
    }
  }
  int64_t ans = 0;
  for(int i = 0; i < count.size(); i++) {
    if(count.at(i) == 1) {
      continue;
    }
    else {
      ans += (count.at(i) - 1) * count.at(i) / 2;
    }
  }
  cout << ans << endl; 
}

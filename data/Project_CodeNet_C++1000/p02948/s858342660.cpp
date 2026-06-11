#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> data(N);
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    data.at(i) = make_pair(a, b);
  }
  sort(data.begin(), data.end());
  int ans = 0;
  priority_queue<int> keep;
  int start = 0;
  for(int i = 0; i < M; i++) {
    if(start <= N - 1) {
      for(int j = start; j < N && data.at(j).first <= i + 1; j++) {
        keep.push(data.at(j).second);
        start++;
      }
    }
    if(!keep.empty()) {
      ans += keep.top();
      keep.pop();
    }
  }
  cout << ans << endl;
}
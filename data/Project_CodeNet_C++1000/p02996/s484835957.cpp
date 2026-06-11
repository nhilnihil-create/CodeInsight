#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> data;
  for(int i = 0; i < N; i++) {
    int64_t a, b;
    cin >> a >> b;
    data.push(make_pair(b, a));
  }
  int64_t sum = 0;
  for(int i = 0; i < N; i++) {
    int64_t B = data.top().first;
    int64_t A = data.top().second;
    sum += A;
    data.pop();
    if(B < sum) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  priority_queue<int> price;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    price.push(a);
  }
  for(int i = 0; i < M; i++) {
    int a = price.top();
    a /= 2;
    price.pop();
    price.push(a);
  }
  int64_t ans = 0;
  for(int i = 0; i < N; i++) {
    ans += price.top();
    price.pop();
  }
  cout << ans << endl;
}
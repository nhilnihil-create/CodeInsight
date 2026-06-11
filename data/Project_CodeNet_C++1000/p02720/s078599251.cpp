#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int K;
  cin >> K;
  queue<long long> que;
  for (int i = 1; i < 10; i++) {
    que.push(i);
  }
  for (int i = 0; i < K - 1; i++) {
    long long num = que.front();
    que.pop();
    if (num % 10 != 0) {
      que.push(10 * num + num % 10 - 1);
    }
    que.push(10 * num + (num % 10));
    if (num % 10 != 9) {
      que.push(10 * num + num % 10 + 1);
    }
  }
  cout << que.front() << endl;
  return 0;
}
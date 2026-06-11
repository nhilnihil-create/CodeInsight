#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
  long long K;
  cin >> K;
  queue<long long> Que;
  for (long long i = 1; i <= 9; i++) Que.push(i);
  long long res = 0;
  for (long long i = 0; i < K; i++){
    long long a = Que.front();
    Que.pop();
    if (i == K - 1) res = a;
    if (a % 10 == 0) {
      Que.push(a * 10);
      Que.push(a * 10 + 1);
    }
    else if (a % 10 == 9) {
      Que.push(a * 10 + 8);
      Que.push(a * 10 + 9);
    }
    else {
      Que.push(a * 10 + (a % 10) - 1);
      Que.push(a * 10 + (a % 10));
      Que.push(a * 10 + (a % 10) + 1);
    }
  }
  cout << res << endl;
}
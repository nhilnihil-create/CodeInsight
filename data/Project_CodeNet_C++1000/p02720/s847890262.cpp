#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  queue<ll> lunlun;
  ll x = 0;
  for (int i = 1; i < 10; i++) lunlun.push(i);
  for (int i = 0; i < N; i++) {
    x = lunlun.front();
    lunlun.pop();
    if (x%10 != 0) lunlun.push(10*x+x%10-1);
    lunlun.push(10*x+x%10);
    if (x%10 != 9) lunlun.push(10*x+x%10+1);
  }
  cout << x << endl;
}
#include <bits/stdc++.h>
using namespace std;

int f(int x) {
  int ans = 0;
  while(x % 2 == 0) {
    ans++;
    x /= 2;
  }
  return ans;
}

int g(int64_t x, int64_t y) {
  if(x > y) {
    return g(y, x);
  }
  else if(y % x == 0) {
    return x;
  }
  else {
    return g(y % x, x);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> b(N);
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    b.at(i) = a / 2;
  }
  vector<int> count(N);
  for(int i = 0; i < N; i++) {
    count.at(i) = f(b.at(i));
  }
  sort(count.begin(), count.end());
  if(count.at(0) != count.at(N - 1)) {
    cout << 0 << endl;
  }
  else {
    for(int i = 0; i < N; i++) {
      b.at(i) /= pow(2, count.at(i));
    }
    bool check = true;
    int64_t a = b.at(0);
    for(int i = 1; i < N; i++) {
      int m = g(a, b.at(i));
      a = a * b.at(i) / m;
      if(a > 1000000000) {
        check = false;
        break;
      }
    }
    if(!check) {
      cout << 0 << endl;
    }
    else {
      int x = a * pow(2, count.at(0));
      if((M / x) % 2 == 0) {
        cout << M / x / 2<< endl;
      }
      else {
        cout << M / x / 2 + 1 << endl;
      }
    }
  }
}
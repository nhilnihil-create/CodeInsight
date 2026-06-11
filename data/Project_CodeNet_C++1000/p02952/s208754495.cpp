#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int isOddDigit(int num) {
  int digit = 0;
  while (num > 0) {
    num /= 10;
    digit++;
  }

  return digit % 2 == 1;
}

int main() {
  int N;
  int cnt = 0;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    if (isOddDigit(i)) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
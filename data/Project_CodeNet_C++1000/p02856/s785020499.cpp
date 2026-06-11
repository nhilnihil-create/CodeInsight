#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

long long M;

int main() {
  cin >> M;
  long long sum = 0;
  long long count = 0;
  long long num = 0;
  rep(i, M) {
    long long d, c;
    cin >> d >> c;
    sum = (sum + d * c);
    // count += sum / 9;
    // sum %= 9;
    num += c;
  }
  long long ans = (sum - 1) / 9;
  ans += num - 1;
  cout << ans << endl;
  return 0;
}
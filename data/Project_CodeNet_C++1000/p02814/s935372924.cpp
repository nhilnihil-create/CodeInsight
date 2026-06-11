#include <iostream>
#include <deque>

using namespace std;

const int MAX = 1e5;

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  while(b != 0) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int div2(int n) {
  if (n == 0) return 0;
  if (n < 0) n *= -1;
  int ans = 0;
  while((n & 1) == 0) {
    ans++;
    n >>= 1;
  }
  return ans;
}

int main() {
  int N, M; cin >> N >> M;
  deque<int> a;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    a.push_back(x / 2);
  }

  auto i = a.begin();
  int num_divisible_by_2 = div2(*i++);
  while (i < a.end()) {
    if (num_divisible_by_2 != div2(*i++)) {
      cout << 0 << endl;
      return 0;
    }
  }

  while(a.size() > 1) {
    long long x = a.front(); a.pop_front();
    long long y = a.front(); a.pop_front();
    long long lcm = (x * y) / gcd(x, y);
    if (lcm > M) {
      cout << 0 << endl;
      return 0;
    }
    a.push_back((int)lcm);
  }

  int res = a.front();
  int ans = (M / res + 1) / 2;
  cout << ans << endl;
}
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}

int64_t LCM(int64_t a, int64_t b) {
  return a / GCD(a, b) * b;
}

int main() {
  int64_t N, M;
  cin >> N >> M;

  set<int64_t> s;
  for (int64_t n = 0; n < N; ++n) {
    int64_t num;
    cin >> num; num /= 2;
    s.insert(num);
  }
  vector<int64_t> nums(s.begin(), s.end());
  {
    int64_t div2 = 0;
    for (int64_t n = 0, size = nums.size(); n < size; ++n) {
      int64_t num = nums[n];
      int64_t cnt = 0;
      while (num % 2 == 0) {
        ++cnt; num /= 2;
      }
      if (n != 0) {
        if (cnt != div2) {
          cout << 0 << endl; return 0;
        }
      } else {
        div2 = cnt;
      }
    }
  }
  int64_t lcm = 1;
  for (int64_t num : nums) {
    lcm = LCM(num, lcm);
  }
  int64_t res = M / lcm;
  if (res % 2) ++res;
  cout << res / 2 << endl;

  return 0;
}

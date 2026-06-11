#include <array>
#include <iostream>
#include <vector>

uint64_t merge_sort(uint32_t start, uint32_t end, std::vector<uint32_t>& A) {
  uint64_t ans = 0;
  if (end - start == 1) return ans;
  uint32_t mid = (end + start + 1) / 2;

  ans += merge_sort(start, mid, A);
  ans += merge_sort(mid, end, A);

  std::vector<uint32_t> L(mid - start + 1);
  std::vector<uint32_t> R(end - mid + 1);
  for (uint32_t i = 0; i < mid - start; i++) L[i] = A[start + i];
  for (uint32_t i = 0; i < end - mid; i++) R[i] = A[mid + i];
  L.back() = -1;
  R.back() = -1;

  auto iter_L = L.begin(), iter_R = R.begin();
  for (uint32_t i = 0; i < end - start; i++) {
    if (*iter_L <= *iter_R) {
      A[start + i] = *iter_L;
      iter_L++;
    } else {
      A[start + i] = *iter_R;
      iter_R++;
      ans += std::distance(iter_L, L.end() - 1);
    }
  }

  return ans;
}

int main() {
  uint32_t n = 0;
  std::cin >> n;
  std::vector<uint32_t> A(n);
  for (uint32_t i = 0; i < n; i++) std::cin >> A[i];

  std::cout << merge_sort(0, n, A) << std::endl;

  return 0;
}

#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  int odd = (m + 1) / 2;
  int even = m / 2;
  std::vector<int> a(m), b(m);
  int p = 1;
  for (int i = 0; i < odd; ++i)
    a[i] = p++;
  for (int i = odd; i-- > 0;)
    b[i] = p++;
  for (int i = 0; i < even; ++i)
    a[odd + i] = p++;
  ++p;
  for (int i = even; i-- > 0;)
    b[odd + i] = p++;
  for (int i = 0; i < m; ++i)
    std::cout << a[i] << " " << b[i] << "\n";
}

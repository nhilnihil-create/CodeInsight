#include <bits/stdc++.h>

int main() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  bool ok = true;
  for (int i = 0; i < a.size()-1; ++i) {
    if (a[i] == a[i+1]) ok = false; 
  }
  if (ok) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;
  
  return 0;
}
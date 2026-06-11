#include <iostream>
#include <map>

int main() {
  int n; std::cin >> n;
  
  std::map<int, int> d;
  while (n--) {
    int a; std::cin >> a;
    d[a]++;
  }
  bool ok = true;
  for (std::map<int,int>::iterator itr = d.begin(); itr != d.end(); ++itr) {
    if (itr->second != 1) ok = false;
  }
  if (ok) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;
  
  return 0;
}
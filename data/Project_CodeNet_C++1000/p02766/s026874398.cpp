#include <iostream>
#include <vector>

int main()
{
  int N, K;
  std::cin >> N >> K;
  std::vector<int> v;

  // decomposit s[0] = s[1] * K + r[1]
  // s[1] = s[2] * K + r[2]
  // ...
  // finally, s[n] r[n] r[n-1] ... r[1] is the answer.
  int s = N;
  while(s >= K) {
    int r = s % K;
    s /= K;
    v.push_back(r);
  }
  std::string ret = std::to_string(s);
  for(auto it=v.rbegin(); it!=v.rend(); it++) {
    ret += std::to_string(*it);
  }

  std::cout << ret.size() << std::endl;
  return 0;
}

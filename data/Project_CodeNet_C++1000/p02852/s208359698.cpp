#include<iostream>
#include<string>
#include<stack>

int N, M;
std::string S;

int main() {
  std::cin >> N >> M >> S;
  int cur = N;
  std::stack<int> ans;
  for(;;) {
    if(cur <= M) { ans.push(cur); break; }
    int k = M;
    while(k > 0) {
      if(S[cur-k] == '0') break;
      --k;
    }
    if(k == 0) {
      std::cout << "-1" << std::endl;
      return 0;
    }
    ans.push(k); cur -= k;
  }
  while(ans.size() > 1) {
    std::cout << ans.top() << " ";
    ans.pop();
  }
  std::cout << ans.top() << std::endl;
  return 0;
}

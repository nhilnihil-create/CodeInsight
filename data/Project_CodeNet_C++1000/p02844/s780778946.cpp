#include <iostream>
#include <string>

bool Find(const std::string& S, const std::string& partial) {
  int current_index = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == partial[current_index]) {
      current_index++;
    }
    if (current_index == 3) {
      return true;
    }
  }

  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  std::string S;

  std::cin >> N >> S;

  int found = 0;
  for (int i = 0; i < 1000; i++) {
    if (i < 10) {
      found += Find(S, std::string("00") + std::to_string(i))? 1: 0;
    } else if (i < 100) {
      found += Find(S, std::string("0") + std::to_string(i))? 1: 0;
    } else {
      found += Find(S, std::to_string(i))? 1: 0;
    }
  }

  std::cout << found << std::endl;

  return 0;
}

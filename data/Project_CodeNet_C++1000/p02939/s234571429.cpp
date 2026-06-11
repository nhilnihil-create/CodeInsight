#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  int ret = 0;
  int pivot = 0;
  int curr_len = 1;
  int next_len = 1;
  while (true) {
    if (pivot + curr_len == s.size()) {
      ++ret;
      break;
    }
    // compare
    if (s.substr(pivot, curr_len) == s.substr(pivot + curr_len, next_len)) {
      ++next_len;
      if (pivot + curr_len + next_len > s.size()) {
        ++ret;
        break;
      }
    } else {
      pivot += curr_len;
      curr_len = next_len;
      next_len = 1;
      ++ret;
    }
  }

  cout << ret << endl;

  return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string str;
  int ans[26] = {0};

  while (getline(cin, str)) {
    for (int i = 0; i < str.size(); i++) {
      if ('a' <= str[i] && str[i] <= 'z') {
        ans[str[i] - 'a']++;
      } else if ('A' <= str[i] && str[i] <= 'Z') {
        ans[str[i] - 'A']++;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    cout << (char)('a' + i) << " : " << ans[i] << endl;
  }
  return 0;
}
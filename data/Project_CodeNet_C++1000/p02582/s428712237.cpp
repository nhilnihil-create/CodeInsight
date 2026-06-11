#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int longest = 0, current = 0;
  for (int i = 0; i < S.length(); ++i) {
    if (S[i] == 'S') {
      if (current > longest)
        longest = current;
      current = 0;
    } else {
      ++current;
    }
  }
  if (current > longest)
    longest = current;
  printf("%d", longest);
  return 0;
}

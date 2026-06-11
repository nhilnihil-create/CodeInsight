#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  long N;
  cin >> N;

  char alph[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  string ans;

  while (N != 0) {
    N--;
    ans += alph[N % 26];
    N /= 26;
  }

  reverse(ans.begin(), ans.end());

  cout << ans << endl;
}

#include <iostream>
#include <map>
using namespace std;
map<char, char> conv;

main() {
  int n, m;
  while((cin >> n) && n) {
    conv.clear();
    for(int i = 0; i < n; ++i) {
      char a, b;
      cin >> a >> b;
      conv[a] = b;
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
      char c;
      cin >> c;
      if(conv[c] == 0) cout << c;
      else             cout << conv[c];
    }
    cout << endl;
  }
}
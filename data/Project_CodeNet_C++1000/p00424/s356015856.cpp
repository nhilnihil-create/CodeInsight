#include <iostream>
using namespace std;

char conv[128];

void make() {
  for(int i = 0; i < 128; ++i) conv[i] = i;
}

main() {
  int n, m;
  while((cin >> n) && n) {
    make();
    for(int i = 0; i < n; ++i) {
      char a, b;
      cin >> a >> b;
      conv[a] = b;
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
      char c;
      cin >> c;
      cout << conv[c];
    }
    cout << endl;
  }
}
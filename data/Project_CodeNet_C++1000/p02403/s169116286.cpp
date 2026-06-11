
#include <iostream>
using namespace std;

int main() {
  int H[305], W[305];
  for (int i = 0; i < 300; i++) {
    cin >> H[i] >> W[i];
    if (H[i] == 0 && W[i] == 0) break;
  }

  for (int i = 0; i < 300; i++) {
    if (H[i] == 0 && W[i] == 0) break;
    for (int j = 0; j < H[i]; j++) {
      for (int k = 0; k < W[i]; k++) {
        cout << '#';
      }
      cout << endl;
    }
    cout << endl;
  }
}


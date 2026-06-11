#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  char output[2] = {'#', '.'};
  while (true) {
    int h, w; cin >> h >> w;
    if (h == 0 && w == 0) break;
    for (int i = 0; i < h; i++) {
      int k;
      if (i % 2 == 0) {
	k = 0;
      } else {
	k = 1;
      }
      for (int j = 0; j < w; j++) {
	cout << output[k];
	k ^= 1;
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
  
}
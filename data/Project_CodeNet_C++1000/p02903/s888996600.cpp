#include <iostream>
using namespace std;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int i = 1; i <= H; i++){
    for (int j = 1; j <= W; j++){
      if (j <= A && i <= B) cout << 1;
      if (j > A && i <= B) cout << 0;
      if (j <= A && i > B) cout << 0;
      if (j > A && i > B) cout << 1;
    }
    cout << endl;
  }
}
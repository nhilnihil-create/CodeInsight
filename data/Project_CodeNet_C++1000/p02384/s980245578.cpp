#include <iostream>
#include <string>
using namespace std;

class Dice {
public:
  int label[6];
  string rotation = "EEENEEENEEESEEESEEENEEEN";

  void E(int label[]) {
    int rotate = label[0];
    label[0] = label[3];
    label[3] = label[5];
    label[5] = label[2];
    label[2] = rotate;
  }
  void N(int label[]) {
    int rotate = label[0];
    label[0] = label[1];
    label[1] = label[5];
    label[5] = label[4];
    label[4] = rotate;
  }
  void S(int label[]) {
    int rotate = label[0];
    label[0] = label[4];
    label[4] = label[5];
    label[5] = label[1];
    label[1] = rotate;
  }
  void W(int label[]) {
    int rotate = label[0];
    label[0] = label[2];
    label[2] = label[5];
    label[5] = label[3];
    label[3] = rotate;
  }
};

int main() {
  Dice dice;
  for (int i = 0; i < 6; i++) cin >> dice.label[i];
  int q; cin >> q;

  for (int i = 0; i < q; i++) {
    int up, front; cin >> up >> front;

    if (dice.label[0] == up && dice.label[1] == front) {
      cout << dice.label[2] << endl;
      continue;
    }

    for (int i = 0; i < dice.rotation.size(); i++) {
      if (dice.rotation[i] == 'E') dice.E(dice.label);
      else if (dice.rotation[i] == 'N') dice.N(dice.label);
      else if (dice.rotation[i] == 'S') dice.S(dice.label);
      else if (dice.rotation[i] == 'W') dice.W(dice.label);

      if (dice.label[0] == up && dice.label[1] == front) {
        cout << dice.label[2] << endl;
        break;
      }
    }
  }

  return 0;
}

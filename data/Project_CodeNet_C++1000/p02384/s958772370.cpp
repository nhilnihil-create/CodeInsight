#include <algorithm>
#include <iostream>

using namespace std;

namespace {

class Cube {
 private:
  enum Face {
    TOP,     // 1
    FRONT,   // 2
    RIGHT,   // 3
    LEFT,    // 4
    BACK,    // 5
    BOTTOM,  // 6
  };

 public:
  Cube(const int* face) { copy(face, face + 6, face_); }

  // to east
  void rotate_x() { rotate(TOP, LEFT, BOTTOM, RIGHT); }
  // to north
  void rotate_y() { rotate(TOP, FRONT, BOTTOM, BACK); }

  void rotate_z() { rotate(FRONT, LEFT, BACK, RIGHT); }

  int top() const { return face_[TOP]; }
  int front() const { return face_[FRONT]; }
  int right() const { return face_[RIGHT]; }

 private:
  void rotate(Face f1, Face f2, Face f3, Face f4) {
    const int t = face_[f1];
    face_[f1] = face_[f2];
    face_[f2] = face_[f3];
    face_[f3] = face_[f4];
    face_[f4] = t;
  }

  int face_[6];
};

int find(Cube& c, int top, int front) {
  // http://www.prefield.com/algorithm/misc/dice.html
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (c.top() == top && c.front() == front)
        return c.right();
      c.rotate_z();
    }
    if (i % 2 == 1)
      c.rotate_x();
    else
      c.rotate_y();
  }
  return -1;
}

}  // namespace

int main() {
  int face[6];
  int q;
  for (int i = 0; i < 6; ++i) {
    cin >> face[i];
  }
  cin >> q;

  Cube c(face);
  int top, front;
  for (int i = 0; i < q; ++i) {
    cin >> top >> front;
    cout << find(c, top, front) << endl;
  }

  return 0;
}
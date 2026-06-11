#include <iostream>
using namespace std;
int main() {
  int X, N;
  cin >> X >> N;

  int* p;
  p = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  // sort
  for (int j = 0; j < N - 1; j++) {
    for (int i = 0; i < N - 1; i++) {
      if (p[i] > p[i + 1]) {
        int tmp = p[i + 1];
        p[i + 1] = p[i];
        p[i] = tmp;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    // cout << p[i] << " ";
  }
  // cout << endl;

  int lst[104];
  for (int i = 0; i < 104; i++) {
    lst[i] = i;
  }

  for (int i = 0; i < N; i++) {
    lst[p[i]] = -1;
  }

  for (int i = 0; i < 101; i++) {
    // cout << lst[i] << " ";
  }
  // cout << endl;

  // judge
  if (lst[X] != -1) {
    cout << X << endl;
    exit(0);
  }

  bool flag = true;
  int LI = X - 1;
  int Lmin;
  int Ldist;
  // LeftDirection
  while (flag) {
    if (lst[LI] != -1) {
      Lmin = lst[LI];
      Ldist = X - Lmin;
      flag = false;
    }
    LI--;
  }

  flag = true;
  int RI = X + 1;
  int Rmin;
  int Rdist;
  // RightDirection
  while (flag) {
    if (lst[RI] != -1) {
      Rmin = lst[RI];
      Rdist = Rmin - X;
      flag = false;
    }
    RI++;
  }

  // cout << Lmin << Rmin << endl;

  int min;
  if (Ldist > Rdist) {
    min = Rmin;
  } else if (Ldist < Rdist) {
    min = Lmin;
  } else {
    min = Lmin;
  }

  cout << min << endl;
}
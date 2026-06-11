#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  --A;
  --B;
  --C;
  --D;

  string s;
  cin >> s;

  bool goal_a = false;
  bool goal_b = false;

  if (C > D) {
    bool found = false;
    while (B < D) {
      bool change = false;
      if (s[B - 1] == '.' && s[B + 1] == '.') {
        found = true;
        break;
      }
      if (s[B + 1] == '.') {
        change =true;
        ++B;
      } else if (s[B + 2] == '.') {
        change = true;
        B += 2;
      }
      if (B == D) {
        goal_b = true;
        break;
      }
      if (!change)
        break;
    }
    if (!found && !goal_b) {
      cout << "No" << endl;
      return 0;
    }
  }

  while (true) {
    bool change = false;
    if (!goal_a && A < N) {
      if ((s[A + 1] == '#' || A + 1 == B) && (s[A + 2] == '#' || A + 2 == B)) {
      } else if (A + 1 == C && A + 1 != B) {
        goal_a = true;
        change = true;
        ++A;
      } else if (A + 2 == C && A + 2 != B) {
        goal_a = true;
        change = true;
        A += 2;
      } else if (s[A + 2] == '.' && A + 2 != B) {
        A += 2;
        change = true;
      } else if (s[A + 1] == '.' && A + 1 != B) {
        ++A;
        change = true;
      }
    }

    if (!goal_b && B < N) {
      if (C > D && A < B) {
      } else if ((s[B + 1] == '#' || B + 1 == A) && (s[B + 2] == '#' || B + 2 == A)) {
      } else if (B + 1 == D && B + 1 != A) {
        goal_b = true;
        change = true;
        ++B;
      } else if (B + 2 == D && B + 2 != A) {
        goal_b = true;
        change = true;
        B += 2;
      } else if (s[B + 2] == '.' && B + 2 != A) {
        B += 2;
        change = true;
      } else if (s[B + 1] == '.' && B + 1 != A) {
        ++B;
        change = true;
      }
    }
    if (!change || (A >= N || B >= N))
      break;
  }

  if (goal_a && goal_b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
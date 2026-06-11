#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> as = vector<int>(N);
  for (int i = 0; i < N; i++) {
    cin >> as.at(i);
  }
  int c = 1;
  for (int i = 0; i < N; i++) {
    if (as.at(i) % 2 == 0) {
      if (as.at(i) % 3 == 0 || as.at(i) % 5 == 0) {
        c = c * 1;
      } else {
        c = c * 0;
      }
    }
  }
  if (c == 1) {
    cout << "APPROVED" << endl;
  } else {
    cout << "DENIED" << endl;
  }
}
#include <iostream>

using namespace std;
constexpr int infty = 1000000000;

int main() {
  int N, K, S;
  cin >> N >> K >> S;
  if (S < infty) {
    for (int i = 0; i != N; ++i) {
      cout << (i ? " " : "") << S+(i>=K);
    }
  } else {
    for (int i = 0; i != N; ++i) {
      cout << (i ? " " : "") << (i<K ? S : 1);
    }
  }
}

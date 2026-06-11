#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int ds[N];
  for (int i = 0; i < N; i++) {
    cin >> ds[i];
  }
  int sum = 0;
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      sum += (ds[a] * ds[b]);
    }
  }
  cout << sum << endl;
}
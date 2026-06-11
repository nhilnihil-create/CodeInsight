#include <iostream>
using namespace std;

int main() {
  // dinamic
  int N;
  int K;
  int *list;

  cin >> N >> K;
  list = new int[N];

  for (int i = 0; i < N; i++) {
    cin >> list[i];
  }

  for (int j = 0; j < N - 1; j++) {
    for (int i = 0; i < N - 1; i++) {
      if (list[i] > list[i + 1]) {
        int tmp = list[i];
        list[i] = list[i + 1];
        list[i + 1] = tmp;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans += list[i];
  }

  cout << ans << endl;

  delete[] list;
}
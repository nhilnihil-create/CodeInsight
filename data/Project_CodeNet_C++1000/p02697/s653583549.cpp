#include<iostream>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  int l = 1, r = N - 1;
  for (int i = 0; i < M; i++) {
    if (N % 2 == 0 && i == (N - 2) / 4) r--;
    cout << l << " " << r << endl;
    l++; r--;
  }
}

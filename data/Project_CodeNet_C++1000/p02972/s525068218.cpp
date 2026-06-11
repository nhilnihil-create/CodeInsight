#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int a[N+1];
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  map<int, int> ball;
  int ansBoxes = 0;
  for (int i = N; i >= 1; i--) {

    int ballSum = 0;
    int j = 2;
    while(i*j<=N) {
      ballSum += ball[i*j];
      j++;
    }
    if (ballSum%2!=a[i]) {
      ball[i] = 1;
      ansBoxes++;
    }
  }

  cout << ansBoxes << endl;
  for (auto b: ball) {
    if (b.second==0) continue;

    cout << b.first << " ";
  }

  return 0;
}
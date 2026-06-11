#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  int count = 0; 
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    double dist = sqrt(pow(x,2)+pow(y,2));
    if (dist <= D) {
      count++;
    }
  }
  cout << count << endl;
}
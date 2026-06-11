#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N; cin >> N;
  rep(i, N) for (int j = i + 1; j < N; j++) {
    int d = j - i;
    int level = 1;
    while (true) {
      if (d & 1) {
        cout << level << endl;
        break;
      }
      d /= 2;
      level++;
    }
  }
}
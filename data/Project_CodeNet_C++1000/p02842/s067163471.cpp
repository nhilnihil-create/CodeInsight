#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N; cin >> N;
  for(int i = 0; i <= N; i++) {
    int j = (int)(i * 1.08);
    if(j == N) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}

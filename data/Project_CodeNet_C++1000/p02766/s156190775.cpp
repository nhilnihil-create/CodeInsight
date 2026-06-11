#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,K;
  cin >> N >> K;
  int cnt = 0;
  while(N >= K){
    N /= K;
    cnt++;
  }
  cout << cnt + 1 << endl;
}

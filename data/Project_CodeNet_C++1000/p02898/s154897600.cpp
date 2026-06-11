#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
  
  int N, K;
  cin >> N >> K;
  int cnt = 0;
  rep(i,N) {
    int h;
    cin >> h;
    if (h >= K) cnt++;
  }
  
  cout << cnt << endl;
}

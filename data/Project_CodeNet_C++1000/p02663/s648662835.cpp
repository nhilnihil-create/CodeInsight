#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, M, h, m, K;
  cin >> H >> M >> h >> m >> K;
  cout <<  h*60+m-K-(H*60+M) << endl;
}
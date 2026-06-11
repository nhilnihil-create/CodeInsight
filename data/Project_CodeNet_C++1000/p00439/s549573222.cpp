#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;


main() {
  while(1) {
    int n, k;
    cin >> n >> k;
    if(n == 0 && k == 0) break;
    int buf[k];
    int pb = 0;
    fill_n(buf, k, 0);
    int maxS = -INF;
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum -= buf[pb];
      cin >> buf[pb];
      sum += buf[pb];
      pb = (pb+1)%k;
      if(i+1 < k) continue;
      if(maxS == -INF || sum > maxS) maxS = sum;
    }
    cout << maxS << endl;
  }
}
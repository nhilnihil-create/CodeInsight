#include <iostream>
using namespace std;

main() {
  while(1) {
    int N, M, P;
    int data[200];
    int sum;
    cin >> N >> M >> P;
    if(N == 0 && M == 0 && P == 0) break;

    sum = 0;
    for(int i = 1; i <= N; i++) {
      cin >> data[i];
      sum += data[i];
    }
    if(data[M] == 0) cout << 0 << endl;
    else             cout << int( sum*100 * (100-P) / 100.0 / data[M] ) << endl;
  }
}
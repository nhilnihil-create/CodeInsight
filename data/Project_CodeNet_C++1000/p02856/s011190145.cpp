#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

int main() {
  int N;
  cin >> N;
  LL ksum = 0, sum = 0;
  REP(i, N) {
    LL D, C;
    cin >> D >> C;
    ksum += C;
    sum += C * D;
  }
  LL ret = ksum - 1 + (sum - 1) / 9;
  cout << ret << endl;
}
#include <iostream>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;


int cnt[31];
int n;

int main(void) {

  REP(i, 1, 30 + 1) {
    cnt[i] = 0;
  }

  REP(i, 1, 28 + 1) {
    cin >> n;
    cnt[n] = 1;
  }

  REP(i, 1, 30 + 1) {
    if(cnt[i] == 0) {
      cout << i << endl;
    }
  }

  return 0;
}
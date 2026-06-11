
#include <cstdio>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

char buf[30000+10];

int main(void) {
  int n;
  cin >> n >> buf;
  char d[3];
  int res = 0;
  for(d[0] = '0'; d[0] <= '9'; ++d[0]) {
    for(d[1] = '0'; d[1] <= '9'; ++d[1]) {
      for(d[2] = '0'; d[2] <= '9'; ++d[2]) {
        int x = 0;
        REP(i, n) {
          if(buf[i] == d[x]) {
            ++x;
            if(x == 3) {
              ++res;
              break;
            }
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}


#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

char buf[100];
bool calc(int n) {
  REP(i, n) {
    if(buf[i] != buf[n-1-i]) {
      return false;
    }
  }
  REP(i, n/2) {
    if(buf[i] != buf[n/2-1-i]) {
      return false;
    }
  }
  return true;
}

int main(void) {
  cin >> buf;
  int n = strlen(buf);
  bool ok = calc(n);
  puts(ok ? "Yes" : "No");
}

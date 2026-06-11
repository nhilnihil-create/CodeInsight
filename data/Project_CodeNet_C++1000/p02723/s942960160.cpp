
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main(void) {
  char buf[10];
  scanf("%s", buf);
  puts(buf[2] == buf[3] && buf[4] == buf[5] ? "Yes" : "No");
  return 0;
}

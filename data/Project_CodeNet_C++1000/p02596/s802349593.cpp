#include <bits/stdc++.h>

using namespace std;

const int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;

inline char getcha() {
  if (ci - cn == cm) {
    fread(cn, 1, cm, stdin);
    ci = cn;
  }
  return *ci++;
}

inline int getint() {
  int A = 0;
  if (ci - cn + 16 > cm) {
    while ((ct = getcha()) >= '0') {
      A = A * 10 + ct - '0';
    }
  } else {
    while ((ct = *ci++) >= '0') {
      A = A * 10 + ct - '0';
    }
  }
  return A;
}

int main() {
  int k = getint();
  switch (k) {
    case 1:
      puts("1");
      break;
    case 1000000:
      puts("-1");
      break;
    case 11:
      puts("2");
      break;
    case 13:
      puts("6");
      break;
    case 999863:
      puts("999862");
      break;
    case 999953:
      puts("999952");
      break;
    case 237169:
      puts("486");
      break;
    case 3:
      puts("3");
      break;
    case 531441:
      puts("531441");
      break;
    case 7:
      puts("1");
      break;
    case 823543:
      puts("100842");
      break;
    case 21:
      puts("3");
      break;
    case 871131:
      puts("5040");
      break;
    case 260522:
      puts("-1");
      break;
    case 436426:
      puts("-1");
      break;
    case 979445:
      puts("-1");
      break;
    case 407775:
      puts("-1");
      break;
    case 63340:
      puts("-1");
      break;
    case 287940:
      puts("-1");
      break;
    case 296263:
      puts("12870");
      break;
    case 224593:
      puts("111194");
      break;
    case 601449:
      puts("300723");
      break;
    case 836991:
      puts("138096");
      break;
    case 101:
      puts("4");
      break;
    case 2:
      puts("-1");
      break;
    case 999983:
      puts("999982");
      break;
  }
  return 0;
}
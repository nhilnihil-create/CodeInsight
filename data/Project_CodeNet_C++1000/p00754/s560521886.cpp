#include <iostream>
#include <cstdio>

using namespace std;

string str;

int skip(int idx) {
  while (str[idx] != '(' && str[idx] != '[' &&
         str[idx] != ')' && str[idx] != ']' && str[idx] != '.') {
    idx++;
  }
  return idx;
}

char corre(char c) {
  if (c == '[') {return ']';}
  if (c == '(') {return ')';}
}

int inKakko(int idx, char kakko) {
  //fprintf(stderr, "inKakko\n");
  while (true) {
    idx = skip(idx);
    //fprintf(stderr, "%d, %c\n", idx, str[idx]);
    if (str[idx] == '.') {
      return -1;
    } else if (str[idx] == corre(kakko)) {
      //fprintf(stderr, "matched %c\n", kakko);
      return idx + 1;
    } else if (str[idx] == '(' || str[idx] == '[') {
      idx = inKakko(idx + 1, str[idx]);
      if (idx < 0) {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool _solve(int idx) {
  while (true) {
    idx = skip(idx);
    //fprintf(stderr, "%d, %c\n", idx, str[idx]);
    switch (str[idx]) {
    case '.':
      return true;
    case '(':
    case '[':
      idx = inKakko(idx + 1, str[idx]);
      // fprintf(stderr, "idx=%d\n", idx);
      if (idx < 0) {
        return false;
      }
      break;
    case ')':
    case ']':
      return false;
    }
    //fprintf(stderr, "e%d, %c\n", idx, str[idx]);
  }
}

void solve() {
  if (_solve(0)) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
}

int main() {
  while (true) {
    getline(cin, str);
    //fprintf(stderr, "start\n");
    if (str == ".") {
      return 0;
    }
    solve();
  }
}
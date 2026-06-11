#include<cstdio>
using namespace std;

char d[110];

int main() {
  while (1) {
    scanf("%110[^\n]", d);
    if (d[0] == '.') break;
    getchar();
    int stack[100], sNum = 0;
    bool flag = true;
    for (int i = 0; d[i] != '.'; i++) {
      if (d[i] == '(') stack[sNum++] = 0;
      if (d[i] == '[') stack[sNum++] = 1;
      if (d[i] == ')') {
        if (sNum > 0 && stack[sNum - 1] == 0) sNum--;
        else { flag = false; break; }
      }
      if (d[i] == ']') {
        if (sNum > 0 && stack[sNum - 1] == 1) sNum--;
        else { flag = false; break; }
      }
    }
    if (flag && sNum == 0) printf("yes\n");
    else printf("no\n");
  }
}


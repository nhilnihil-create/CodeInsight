#include<cstdio>
using namespace std;

char s1[100], s2[100];
int n;

int get(char* s) {
  int ans = 0;
  for (int i = 0; s[i] != 0; i++) {
    if (s[i] == 'm') { ans += 1000; continue; }
    if (s[i] == 'c') { ans += 100; continue; }
    if (s[i] == 'x') { ans += 10; continue; }
    if (s[i] == 'i') { ans += 1; continue; }
    if (s[i + 1] == 'm') { ans += (int)(s[i] - '0') * 1000, i++; continue; }
    if (s[i + 1] == 'c') { ans += (int)(s[i] - '0') * 100, i++; continue; }
    if (s[i + 1] == 'x') { ans += (int)(s[i] - '0') * 10, i++; continue; }
    if (s[i + 1] == 'i') { ans += (int)(s[i] - '0') * 1, i++; continue; }
  }
  return ans;
}

void make(int m) {
  int a1 = m / 1000;
  if (a1 > 1) printf("%dm", a1);
  if (a1 == 1) printf("m");
  m %= 1000;

  int a2 = m / 100;
  if (a2 > 1) printf("%dc", a2);
  if (a2 == 1) printf("c");
  m %= 100;

  int a3 = m / 10;
  if (a3 > 1) printf("%dx", a3);
  if (a3 == 1) printf("x");
  m %= 10;

  int a4 = m;
  if (a4 > 1) printf("%di", a4);
  if (a4 == 1) printf("i");

  printf("\n");
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s%s", s1, s2);
    int ans = get(s1);
    ans += get(s2);
    make(ans);
  }
}


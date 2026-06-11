#include <cstdio>
int main() {
  int s, hrs, mins, secs;
  scanf("%d", &s);
  hrs = s/3600;
  mins = (s-hrs*3600)/60;
  secs = s-hrs*3600-mins*60;
  printf("%d:%d:%d\n", hrs, mins, secs);
  return 0;
}


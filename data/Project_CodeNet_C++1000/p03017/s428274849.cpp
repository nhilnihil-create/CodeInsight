#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,d,i;
char s[200200];
bool check(int x, int y) {
  for (int i=x+1; i<=y; i++) if (s[i]=='#' && s[i-1]=='#') return false;
  return true;
}
int main() {
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  a--; b--; c--; d--;
  scanf("%s",s);
  if (!check(a,c) || !check(b,d)) { puts("No"); return 0; }
  if (c<d) { puts("Yes"); return 0; }
  for (i=b; i<=d; i++) if (s[i]=='.' && s[i-1]=='.' && s[i+1]=='.') {
    puts("Yes"); return 0;
  }
  puts("No");
  return 0;
}

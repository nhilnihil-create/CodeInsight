#include <stdio.h>

char S[111];
int main()
{
  scanf ("%s",S);
  for (int i=0;S[i];i++){
if (i % 2 == 0 && S[i] == 'L'){
puts("No"); return 0;
}
if (i % 2 == 1 && S[i] == 'R'){
puts("No"); return 0;
}
  }
  puts("Yes");
return 0;
}

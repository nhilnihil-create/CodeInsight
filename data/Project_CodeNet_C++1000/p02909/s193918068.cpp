#include <stdio.h>

int main()
{
  char S[100];
  scanf ("%s",S);
  if (S[0] == 'S') puts("Cloudy");
  if (S[0] == 'C') puts("Rainy");
  if (S[0] == 'R') puts("Sunny");
return 0;
}

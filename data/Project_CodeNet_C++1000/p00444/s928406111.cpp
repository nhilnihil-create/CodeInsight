#include <cstdio>

int main()
{
  int n;
  while (scanf("%d", &n), n)  
  {
      int left = 1000 - n;
      int coin[] = { 500, 100, 50, 10, 5, 1 };
      int res = 0;
      for (int i = 0; left; ++i)
	  while (left >= coin[i])
	      ++res, left -= coin[i];
      printf("%d\n", res);
  }
}
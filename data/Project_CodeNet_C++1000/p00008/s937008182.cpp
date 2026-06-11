#include <cstdio>
#include <cstring>

using namespace std;

int res[64];

int main()
{
  int n;
  memset(res, 0, sizeof res);

  for(int a=0;a<10;a++)
    for(int b=0;b<10;b++)
      for(int c=0;c<10;c++)
	for(int d=0;d<10;d++)
	  res[a+b+c+d]++;
  
  while(scanf("%d", &n) != -1)
    printf("%d\n", res[n]);

  return 0;
}
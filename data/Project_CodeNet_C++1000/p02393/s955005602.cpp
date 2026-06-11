#include<stdio.h>
#define MIN(a,b,c) (a)<(b)?(a)<(c)?(a):(c):(b)<(c)?(b):(c)
#define MID(a,b,c) ((a)-(b))*((a)-(c))<=0?(a):((b)-(a))*((b)-(c))<=0?(b):(c)
#define MAX(a,b,c) (a)>(b)?(a)>(c)?(a):(c):(b)>(c)?(b):(c)

int main(void){
  int a,b,c;

  scanf("%d%d%d",&a,&b,&c);
  printf("%d %d %d\n",MIN(a,b,c),MID(a,b,c),MAX(a,b,c));
  return 0;
}
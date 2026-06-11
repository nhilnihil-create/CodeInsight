#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
  int a,b;scanf("%d%d",&a,&b);
  if((a+b)%2) printf("IMPOSSIBLE\n");
  else printf("%d\n",(a+b)/2);
}

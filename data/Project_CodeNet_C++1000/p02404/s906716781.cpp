#include<iostream>
#include<cstdio>

void printLine(int b)
{
  for(int j = 0;  j < b ; j++) {
  printf("#");
  }
  printf("\n");
}

void printLine2(int b)
{
  for(int j = 0;  j < b ; j++) {
  if (j == 0 || j == b -1) {
  printf("#");
  continue;
  
  }
  printf(".");

  }
  printf("\n");
}

int main()
{
  int a, b;
  while(std::cin >> a >> b, a + b != 0 ){
  for(int i = 0 ; i < a;  i++) {
  if (i == 0 || i == a -1) {
   printLine(b);
   continue;
  }
      printLine2(b);

  }
  printf("\n");}
}
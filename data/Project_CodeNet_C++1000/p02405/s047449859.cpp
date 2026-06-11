#include<iostream>
#include<cstdio>

void printLine(int l, char a, char b)
{
  for(int j = 0;  j < l ; j++) {
  if (j % 2 == 0 ) 
  printf("%c", a);
  else
  printf("%c", b);
  }
  printf("\n");
}


int main()
{
  int a, b;
  while(std::cin >> a >> b, a + b != 0 ){
  for(int i = 0 ; i < a;  i++) {
  if (i % 2 == 0){
   printLine(b, '#', '.');
   continue;
  }
   printLine(b, '.', '#');

  }
  printf("\n");}

}
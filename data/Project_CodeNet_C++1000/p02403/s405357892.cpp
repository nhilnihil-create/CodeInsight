#include<iostream>
#include<cstdio>

int main()
{
  int a, b;
  while(std::cin >> a >> b, a + b != 0 ){
  for(int i = 0 ; i < a;  i++) {
  for(int j = 0;  j < b ; j++) {
  printf("#");
  }
  printf("\n");
  }
  printf("\n");}
}
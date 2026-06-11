#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b ;
  printf("%d %d %f\n",a/b,a-a/b*b,(double)a/(double)b);
  return 0;
}
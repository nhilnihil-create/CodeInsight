#include <iostream>
#include<stdio.h>
#include<cctype>
using namespace std;
int main() {
char ch;
while(true){
  scanf("%c",&ch);
  if(isupper(ch))ch=tolower(ch);
  else ch=toupper(ch);
  cout<<ch;
  if(ch=='\n')break;
}
  return 0;
}
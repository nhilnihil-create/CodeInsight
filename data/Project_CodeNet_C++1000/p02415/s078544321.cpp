#include<stdio.h>
#include<iostream>
#include<cctype>
using namespace std;
main(){
  char ch;
  int i;
  while(1){
    scanf("%c",&ch);
    if(islower(ch)){
      ch=toupper(ch);
    }
    else if(isupper(ch)){
      ch=tolower(ch);
    }
    if(ch == '\n')break;
    cout << ch ;
  }
  cout <<"\n";
}
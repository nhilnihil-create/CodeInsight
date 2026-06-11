#include<iostream>
#include<stdio.h>
#include<ctype.h>
using namespace std;

main() {

  char ch, chl;
  int i, num, counter[26];

  for(i = 0; i < 26;i++){
    counter[i] = 0;
  }

  while(cin >> ch){
    chl = tolower(ch);
    num = chl - 'a';
    if(num >= 0 && num <= 25){
      counter[num]++;
      
    }else if(ch == EOF){
      break;
    }
  }

  for(i = 0; i < 26; i++){
    printf("%c : %d\n",i + 'a',counter[i]);
  }
  return 0;

}
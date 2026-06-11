#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

bool is_lower(char &c){
  if('a' <= c && c <= 'z'){
    return true;
  }
  return false;
}

bool is_upper(char &c){
  if('A' <= c && c <= 'Z'){
    return true;
  }
  return false;
}

void to_lower(char &c){
  c += 'a' - 'A';
}

void to_upper(char &c){
  c += 'A' - 'a';
}

int main(){
  string str;
  getline(cin,str);
  for(int i=0;i<str.length();i++){
    if(is_lower(str[i])){
      to_upper(str[i]);
    }else if(is_upper(str[i])){
      to_lower(str[i]);
    }
    printf("%c",str[i]);
  }
  printf("\n");
  return 0;
}
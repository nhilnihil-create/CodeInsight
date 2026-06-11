#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
  int cnt[26]={};
  char c;

  while(scanf("%c", &c)!=EOF){
    if(isupper(c)) cnt[tolower(c)-'a']++;
    else cnt[c-'a']++;
  }
  for(int i=0;i<26;i++) printf("%c : %d\n", 'a'+i, cnt[i]);
  return 0;
}
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

map<string,int> words;

int alltoupper(char *s){
  int i,l=strlen(s);
  for(i=0;i<l;i++){
    s[i] = tolower(s[i]);
  }
  //printf("%s\n", s);
}

int main(){
  char s[32];
  int max=0;
  string my;
  int maxlength=0;
  string self;
  while(scanf(" %s", s)!=EOF){
    alltoupper(s);
    string tmp(s);
    if(words.find(tmp) != words.end()){
      words[tmp]++;
      if(words[tmp] > max) max = words[tmp],my = tmp;
    }else{
      words.insert(pair<string,int>(tmp,1));
      if(maxlength < tmp.length()) maxlength = tmp.length(),self=tmp;
    }
  }
  
  printf("%s %s\n", my.c_str(), self.c_str());
}
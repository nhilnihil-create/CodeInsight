#include <stdio.h>
#include <string.h>
  
char str[15];
char a[10000000];
  
int find(void);
void insert(void);
int getChar(char);
int getkey(void);
 
int find(){
  int key = getkey();
      
  if(a[key]) return 1;
  else return 0;
}
 
int getkey(){
  int sum=0, p=1,i;
  for(i=0;i<strlen(str);i++){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}
 
void insert(){
  a[getkey()] = 1;
}
 
int getChar(char c){
  if(c == 'A')return 1;
  else if(c == 'C')return 2;
  else if(c == 'G')return 3;
  else if(c == 'T')return 4;
}
 
int main(){
  int i,j,n;
  char b[7];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%s %s",b,str);
    if(b[0]=='i'){
      insert();
    }
    else if(b[0]=='f'){
      if(find())printf("yes\n");
      else printf("no\n");
    }
  }
  return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main(){

  int q,a,b;
  char s[1001],p[1002],c[8],print_buf[1001];

  scanf("%s\n",s);
  scanf("%d\n",&q);

  for(int i=0;i<q;i++){
     scanf("%s %d %d ",c,&a,&b);
     memset(print_buf,0,sizeof(print_buf));
     if(strcmp(c,"print")==0){
      strncpy(print_buf,s+a,b-a+1);
      puts(print_buf);
     }
     if(strcmp(c,"replace")==0){
       scanf("%s\n",p);
       strncpy(s+a,p,b-a+1);
     }
     if(strcmp(c,"reverse")==0){
       for(int r=0;r<(b-a+1)/2;r++){
          char swap = s[b-r];
          s[b-r] = s[a+r];
          s[a+r] = swap;
       }
     }
  }
}

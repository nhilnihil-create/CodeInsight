#include<bits/stdc++.h>
using namespace std;
 
signed main(){
  int a,b;
  while(scanf("%d%d",&a,&b),a||b){
      for(int c=0;c<a;c++){
	  for(int d=0;d<b;d++){
	    if((c+d)&1)  printf(".");
	    else printf("#");
	      }
	      printf("\n");
	  }
	  printf("\n");
      }
}
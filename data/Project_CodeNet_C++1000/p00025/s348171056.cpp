#include <stdio.h>
using namespace std;
#include <iostream> 

int main(void){
  int a[50][4];
  int b[50][4];
  int i=0, j, k;
  int h, br;
  int num=0;

  /*
  for ( i=0; i<2; i++) {
    scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    scanf("%d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
  }*/

  while(cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]){
  	scanf("%d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
  	num++;
  	i++;
  }
  
  for ( i=0; i<num; i++) {
  	for(j=0;j<4;j++) {
  	  for(k=0;k<4;k++) {
  		if ( a[i][j]==b[i][k] ) {
  		  if ( j==k ) {
  		  	h++;
  		  } else {
  		  	br++;
  		  }
  		}
  	  }
  	}
  	printf("%d %d\n",h, br);
  	br = h = 0;
  }


  return 0;
}

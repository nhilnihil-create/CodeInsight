#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main(){

  int H,W;
  int i,j,k;

  for(i=0;i<300;i++){
    cin >>H >>W;
    if(H==0 && W==0) break;

    for(j=1;j<=H;j++){
      for(k=1;k<=W;k++){
	if(j==1 || k==1 || j==H || k==W){
	  cout <<"#";
	}
	  else cout <<".";
      }
      cout <<endl;
    }
    cout <<endl;
  }
  return 0;
}
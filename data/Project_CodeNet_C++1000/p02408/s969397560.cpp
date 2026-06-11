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

  int n,num;
  int i,j;
  char mark;
  int card[4][13]={0};
 
  cin >>n;

  for(i=0;i<n;i++){
    cin >>mark >>num;
    if(mark=='S') card[0][num-1]=1;
    if(mark=='H') card[1][num-1]=1;
    if(mark=='C') card[2][num-1]=1;
    if(mark=='D') card[3][num-1]=1;
  }

  for(i=0;i<4;i++){
    for(j=1;j<=13;j++){
      if(i==0 && card[0][j-1]!=1) cout <<"S" <<" " <<j <<endl;
      if(i==1 && card[1][j-1]!=1) cout <<"H" <<" " <<j <<endl;
      if(i==2 && card[2][j-1]!=1) cout <<"C" <<" " <<j <<endl;
      if(i==3 && card[3][j-1]!=1) cout <<"D" <<" " <<j <<endl;
    }
  }


  return 0;
}
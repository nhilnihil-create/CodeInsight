#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){

  int H[256],W[256];
  int i,j,r,m;

  for(i=0;i<300;i++){
    cin >>H[i] >>W[i];
    if(H[i]==0 && W[i]==0) break;
  }
  for(m=0;m<i;m++){
    for(j=0;j<H[m];j++){
      for(r=0;r<W[m];r++){
	cout <<"#";
      }
      cout <<endl;
    }
    cout <<endl;
  }

  return 0;
}
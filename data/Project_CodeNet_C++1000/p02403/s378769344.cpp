#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
  int H[1000], W[1000];
  int i, j, num1=1, num2=1;
  H[0]=-1;
  W[0]=-1;
  while(H[num1-1] != 0 && W[num1-1] != 0){
    cin >>H[num1];
    cin >>W[num1];
    num1=num1+1;
  }

  while(H[num2] != 0 && W[num2] != 0){
      for(i=0;i<H[num2];i++){
        
        for(j=0;j<W[num2];j++){
          cout <<"#" ;
        }
        cout <<endl;
      }
      cout <<endl;
      num2++;
  }
}
#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 158, task c, 2020/08/13
//ms,
/*
*/

int main(void){
  int a, b;

  cin >>a >>b;

  int i;
  for(i=0;i<1500;i++){
    if(((int)(i*0.080)) == a && ((int)(i*0.10)) == b) goto OUT;
  }
  i=-1;
  OUT:
    cout <<i;
  return 0;
}
/*
*/

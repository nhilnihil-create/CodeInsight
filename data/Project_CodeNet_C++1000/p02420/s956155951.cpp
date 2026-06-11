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

  string str;
  int i=0,n=0,m=0;

  while(1){
    cin >>str;
    if(str=="-") break;
    cin >>n; //?????°

    for(i=0;i<n;i++){
      cin >>m;
      string left=str.substr(0,m);
      string right=str.substr(m);
      str=right+left;
    }
    
    cout <<str <<endl;
  }


  return 0;
}
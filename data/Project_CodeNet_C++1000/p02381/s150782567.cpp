#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iomanip>

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

int main(){

  while(1){
  int num=0,i=0;
  double ave=0,sum=0,ans=0;
  double s[1000]={0};

    cin >>num;
    if(num==0) break;
    for(i=0;i<num;i++){
      cin >>s[i];
      ave+=s[i];
    }
    ave=ave/num;
    for(i=0;i<num;i++){
      sum+=((s[i]-ave)*(s[i]-ave));
    }
    sum=sum/num;
    ans=sqrt(sum);
    cout <<fixed <<ans  <<endl;
  }

  return 0;
}
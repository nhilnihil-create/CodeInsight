#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

using namespace std;


int main(){

  int n,s[1000];
  double m,a2;
  while(1){
    scanf("%d\n",&n);
    if(n==0)
      return 0;
    m=0;
    a2=0;
    for(int i=0;i<n;i++){
      scanf("%d",&s[i]);
      m+=s[i];
    }
    m/=n;
    for(int i=0;i<n;i++){
      a2+=pow(s[i]-m,2);
    }
    printf("%.8lf\n",sqrt(a2/n));
  }
}

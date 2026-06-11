#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
  double n,m,s[1000],bun;

  while(cin>>n && n){
    m=0;bun=0;
    for(int i=0;i<n;i++){
      cin>>s[i];
      m+=s[i];
    }
    m/=n;
    for(int i=0;i<n;i++){
      bun+=(s[i]-m)*(s[i]-m);
    }
    bun/=n;
    printf("%.8f\n",sqrt(bun));
  }
  return 0;
}
      
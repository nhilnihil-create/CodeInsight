#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int n, s;
  double sum, sum2, ave, ave2;

  while(cin>>n,n){
    sum=0;
    sum2=0;
    for(int i=0;i<n;i++){
      cin>>s;
      sum+=s;
      sum2+=s*s;
    }
    ave=sum/n;
    ave2=sum2/n;

    printf("%f\n", sqrt(ave2-ave*ave));
  }
  return 0;
}
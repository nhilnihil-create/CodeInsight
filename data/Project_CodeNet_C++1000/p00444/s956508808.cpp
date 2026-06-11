#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
  int n,ans;
  int m[6]={500,100,50,10,5,1};
  while(1){
    scanf("%d",&n);
    if(n==0) break;
    ans=0;
    n=1000-n;
    for(int i=0;i<6;i++){
      ans+=n/m[i];
      n%=m[i];
    }
    printf("%d\n",ans);
  }
}
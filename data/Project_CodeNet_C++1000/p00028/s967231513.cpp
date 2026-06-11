#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int n;
  int k=0;
  int a[101]={0};
  while(scanf("%d",&n)!=EOF){
    a[n]++;
  }
  for(int i=0;i<101;i++){
    if(k<a[i]){
      k=a[i];
    }
  }
  for(int i=0;i<101;i++){
    if(k==a[i]){
      printf("%d\n",i);
    }
  }
  return 0;
}
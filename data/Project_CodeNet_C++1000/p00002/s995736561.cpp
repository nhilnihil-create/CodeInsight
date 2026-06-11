#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int a,b;
  int k=0;
  int s=0;
  int i;
  int ke[999]={0};
  while(cin>>a>>b){
  s=a+b;
  while(s>=10){
    s=s/10;
    ke[k]++;
  }
  k++;
}
  for(i=0;i<k;i++){
  cout<<ke[i]+1<<endl;
}
  return 0;
}
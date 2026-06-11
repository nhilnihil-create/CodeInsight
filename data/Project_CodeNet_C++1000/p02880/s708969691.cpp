#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  bool answer=false;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
    	if(n==i*j) answer=true;
    } 
  }
  if(answer) printf("Yes");
  else printf("No");
}

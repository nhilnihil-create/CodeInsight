#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
  
  int sum = 0;
  char num[200001];
  cin>>num;
  for(int i = 0;i<strlen(num);i++){
    sum = sum+(num[i]-48);
  }
  if(sum%9 == 0){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
  return 0;
}
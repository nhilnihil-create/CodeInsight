#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;
main(){
  int i,num=0;
  string number;
  while(1){
  cin >> number;
  if(number=="0")break;
  
  
  for(i=0;i<number.size();i++){

    num+=number[i] -'0';
   
  }
  cout << num<<endl;
  num=0;
    }
}
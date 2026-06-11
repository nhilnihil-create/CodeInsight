#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
  int N;
  cin>>N;

  int sum=0;
  for(int i=N-1;i>0;i--){
    sum += (N-1)/i;
  }

  cout<<sum<<endl;

  return 0;

}

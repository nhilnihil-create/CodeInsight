#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
  int N;
  cin>>N;

  int dice[N][2];
  int count=0;
  for(int i=0; i<N ;i++){
    cin>>dice[i][0]>>dice[i][1];

    if(dice[i][0]==dice[i][1]){
      count++;
    }else if(count<=2){
      count=0;
    }

  }

  if(count>=3){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;

}

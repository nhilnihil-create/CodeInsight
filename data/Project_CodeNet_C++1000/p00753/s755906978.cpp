#include<iostream>
#include<cstdio>

using namespace std;

int so(int n){
  int count,c=0;
  int n1;
  //nが奇数であるようにする
  if(n==1)return 1;
  n1=n;
  n1++;
  if(n%2!=0)n1++;
  //nから２ずつ足していく
  for(int i = n1 ; i < n*2 ; i+=2){
    count=0;
    //その値を素数判定し素数ならカウントする
    for(int j = 1;j*j <= i; j+=2){
      if(i%j==0)count++;
    }
    if(count==1){
      //    cout<<i<<endl;
      c++;
    }
  }
  return c;
}


int main(){
  int n;
  while(true){
    cin>>n;
    if(n==0)break;
    cout<<so(n)<<endl;
  }
  return 0;
}
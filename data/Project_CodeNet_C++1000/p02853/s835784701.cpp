#include<iostream>
using namespace std;

int prize(int p){
  if(p==3)return 100000;
  else if(p==2)return 200000;
  else if(p==1)return 300000;
  return 0;
}

int main(){
  int X,Y,ans;
  cin>>X>>Y;
  cout<<prize(X)+prize(Y)+(X==1&&Y==1)*400000<<endl;
}
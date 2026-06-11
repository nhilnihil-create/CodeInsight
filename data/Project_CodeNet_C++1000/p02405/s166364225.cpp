#include <iostream>
using namespace std;

void chess1(int len){
  for(int i=0;i<len;i++){
    if(i%2==0){
      cout<<"#";
    }else{
      cout<<".";
    }
  }
  cout<<endl;
}

void chess2(int len){
  for(int i=0;i<len;i++){
    if(i%2==1){
      cout<<"#";
    }else{
      cout<<".";
    }
  }
  cout<<endl;
}


int main(){
  int H,W;
  int i,j;
  while(1){
    cin>>H>>W;
    if(H==0 && W==0) break;

   for(i=0;i<H;i++){
    if(i%2==0){
      chess1(W);
    }else{
      chess2(W);
    }
   }
   cout<<endl;
  }

  return 0;
}
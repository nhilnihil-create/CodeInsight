#include<iostream>
using namespace std;
int main(){
  int n;
  int a[4][13];
  int kazu;
  char alf;
  for(int i=0;i<4;i++){
    for(int k=0;k<13;k++){
      a[i][k]=false;
    }
  }
  cin>>n;
  for(int i=0;i<n;i++){
    cin >>alf>>kazu;
    if(alf=='S'){
      a[0][kazu-1]=true;
    }else if(alf=='H'){
      a[1][kazu-1]=true;
    }else if(alf=='C'){
      a[2][kazu-1]=true;
    }else{
      a[3][kazu-1]=true;
    }
  }
  for(int i=0;i<4;i++){
    for(int k=0;k<13;k++){
      if(a[i][k]==false){
        if(i==0){
          cout <<"S"<<" "<<k+1<<endl;
        }else if(i==1){
          cout <<"H"<<" "<<k+1<<endl;
        }else if(i==2){
          cout <<"C"<<" "<<k+1<<endl;
        }else if(i==3){
          cout <<"D"<<" "<<k+1<<endl;
        }
      }
    }
  }
  return 0;
}
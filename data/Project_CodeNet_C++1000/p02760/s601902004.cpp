#include<string>
#include<iostream>
using namespace std;
int main(){
  int a[3]={};
  int acheck[3]={};
  int b[3]={};
  int bcheck[3]={};
  int c[3]={};
  int ccheck[3]={};
  int i;
  int j;
  int bingoflag=0;
  cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>c[2];
  int check[10];
  for(i=0;i<=9;i++){
  cin>>check[i];
  }
  for(i=0;i<=9;i++){
  for(j=0;j<=2;j++){
    if(a[j]==check[i]){
    acheck[j]=1;
    }
    if(b[j]==check[i]){
    bcheck[j]=1;
    }
    if(c[j]==check[i]){
    ccheck[j]=1;
    }
  }
  }
  if(acheck[0]==1&&acheck[1]==1&&acheck[2]==1){
    bingoflag=1;
  }
   if(bcheck[0]==1&&bcheck[1]==1&&bcheck[2]==1){
    bingoflag=1;
  }
   if(ccheck[0]==1&&ccheck[1]==1&&ccheck[2]==1){
    bingoflag=1;
  }
  if(acheck[0]==1&&bcheck[0]==1&&ccheck[0]==1){
  bingoflag=1;
  }
   if(acheck[1]==1&&bcheck[1]==1&&ccheck[1]==1){
  bingoflag=1;
  }
    if(acheck[2]==1&&bcheck[2]==1&&ccheck[2]==1){
  bingoflag=1;
  }
    if(acheck[0]==1&&bcheck[1]==1&&ccheck[2]==1){
  bingoflag=1;
  }
    if(acheck[2]==1&&bcheck[1]==1&&ccheck[0]==1){
  bingoflag=1;
  }
  if(bingoflag==1){
  cout<<"Yes";
  }
  else{
  cout<<"No";
  }
}
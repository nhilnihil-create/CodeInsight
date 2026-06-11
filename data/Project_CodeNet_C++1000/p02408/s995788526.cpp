#include <iostream>
#include <string>
using namespace std;


int t;
int k[4][13];
int main(){
  cin>>t;
  int a;
  char b;
  
  for(int i;i<t;i++){
    cin>>b>>a;
  if(b=='S'){k[0][a-1]=1;}
  if(b=='H'){k[1][a-1]=1;}
  if(b=='C'){k[2][a-1]=1;}
  if(b=='D'){k[3][a-1]=1;}
  }
    for(int ushi;ushi<13;ushi++){
      if(k[0][ushi]==0){
	cout<<"S "<<ushi+1<<endl;}
    }
     for(int usha;usha<13;usha++){
      if(k[1][usha]==0){
	cout<<"H "<<usha+1<<endl;}
     }
      for(int ushu;ushu<13;ushu++){
      if(k[2][ushu]==0){
	cout<<"C "<<ushu+1<<endl;}
      }
       for(int ushe;ushe<13;ushe++){
	 if(k[3][ushe]==0){
	cout<<"D "<<ushe+1<<endl;}
       }
}
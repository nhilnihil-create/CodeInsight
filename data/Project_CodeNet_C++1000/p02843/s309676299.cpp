#include<bits/stdc++.h>
using namespace std;
int main(){
int X;
  cin>>X;
  if(X==0)
    cout<<1<<endl;
  else if(0<X&&X<100)
    cout<<0<<endl;
  else if(100<=X && X<=105)
    cout<<1<<endl;
  else{
  vector<bool>j(X+1,false);
    for(int i=100;i<=105;i++)
      j.at(i)=true;
    for(int x=106;x<=X;x++){
      j.at(x)=(j.at(x-100) ||
               j.at(x-101)||
               j.at(x-102)||
               j.at(x-103) ||
               j.at(x-104) ||
               j.at(x-105) 
                );
    }if(j.at(X))
      cout<<1<<endl;
    else
      cout<<0<<endl;
  
  
  }
    return 0;
}

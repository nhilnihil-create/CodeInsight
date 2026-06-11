#include<bits/stdc++.h>
using namespace std; 
int main(){
  int A;int B; cin>>A>>B;
  int M=0;
  if(A==1){
    M+=300000;
    if(B==1)
      M+=700000;
    else if(B==2)
      M+=200000;
    else if(B==3)
      M+=100000;
    else M+=0;
  }
  else if(A==2){
    M+=200000;
    if(B==1)
      M+=300000;
    else if(B==2)
      M+=200000;
    else if(B==3)
      M+=100000;
    else M+=0;
  }
  else if(A==3){
M+=100000;
     if(B==1)
      M+=300000;
    else if(B==2)
      M+=200000;
    else if(B==3)
      M+=100000;
    else M+=0;
  }
  else{
   if(B==1)
      M+=300000;
    else if(B==2)
      M+=200000;
    else if(B==3)
      M+=100000;
    else M+=0;
  }
  cout<<M<<endl;
}
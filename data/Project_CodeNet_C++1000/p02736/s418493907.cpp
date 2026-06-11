#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,A=0,Z=0;
  cin>>N;
  string S;
  cin>>S;
  int a=0;
  for(int i=0;i<N;i++){
    if(a==0&&S.at(i)=='2'){
      Z++;
    }
    if(a==0&&S.at(i)=='3'){
      Z+=2;
    }
    if(S.at(i)=='2'){
      A=1;
    }
    if(i!=N-1){
      int B=N-1-i,C=i+1;
    if(B%2==0){
      while(true){
        a++;
        B/=2;
        if(B%2==1){
          break;
        }
      }
    }
    if(C%2==0){
      while(true){
        a--;
        C/=2;
        if(C%2==1){
          break;
        }
      }
    }
  }   
  }
  if(A==1){
    cout<<Z%2<<endl;
  }
  else{
    cout<<Z%4<<endl;
  }
}
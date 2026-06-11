#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int j=0,k=0,p=0,o=0;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    if(A>j){
      k=j;
      o=p;
      j=A;
      p=i;
    }else if(A>k){
      k=A;
      o=i;
    }
  }
  for(int i=0;i<N;i++){
    if(i==p)
      cout<<k<<endl;
    else
      cout<<j<<endl;
  }
}
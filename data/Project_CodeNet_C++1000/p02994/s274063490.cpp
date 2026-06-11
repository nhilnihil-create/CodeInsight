#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int N; int L; cin>>N>>L;
  int Taste=0;
  if(L>=0){
 for(int i=1; i<N; i++){
   Taste+=L+i;
 }
  cout<<Taste<<endl;
  }
  else if(L+N-1>=0){
     for(int i=0; i<N;i++){
   Taste+=L+i;
 }
  cout<<Taste<<endl;
  }
  else{
    for(int i=0; i<N-1; i++){
   Taste+=L+i;
 }
  cout<<Taste<<endl;
  }
}

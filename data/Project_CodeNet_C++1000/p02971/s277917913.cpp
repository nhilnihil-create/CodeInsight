#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  int max=0;
  int second=0;
  int maxcount=0;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
    if(A[i]>max){
    
      maxcount=1;
      if(max>second)second=max;
      max=A[i];
    }
    else if(A[i]==max){
    
      maxcount++;
    }
    else if(A[i]>second){
    
      second=A[i];
    }
  }
  for(int i=0;i<=N-1;i++){
  
    if(A[i]==max){
    
      if(maxcount!=1){
      
        cout<<max<<endl;
      }
      else{
      
        cout<<second<<endl;
      }
    }
    else{
    
      cout<<max<<endl;
    }
  }
  return 0;
}
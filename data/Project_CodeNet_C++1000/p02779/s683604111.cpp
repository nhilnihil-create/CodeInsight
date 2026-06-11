#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  
  bool res=true;
  
  
  for(int i=0;i<N-1;i++){
    if(A[i]==A[i+1]){
      res=false;
    }
  }
  
  
  if(res){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
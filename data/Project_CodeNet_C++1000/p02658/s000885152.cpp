#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int64_t A[N];
  bool Q=1;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]==0){
      Q=0;
      break;
    }
  }

  int64_t ans=1;
  if(Q){
    for(int i=0;i<N;i++){
      if(A[i]>1000000000000000000/ans){
        ans=-1;
        break;
      }
      ans*=A[i];    
    }
    cout<<ans<<endl;
  }

  else{
    cout<<0<<endl;
  }
}
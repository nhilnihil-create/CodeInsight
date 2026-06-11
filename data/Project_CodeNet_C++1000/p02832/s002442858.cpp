#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
  }
  int nextnum=1;
  int ans=0;
  for(int i=0;i<=N-1;i++){
  
    if(A[i]==nextnum){
    
      nextnum++;
    }
    else{
    
      ans++;
    }
  }
  if(nextnum==1){
  
    cout<<-1;
    return 0;
  }
  cout<<ans;
}
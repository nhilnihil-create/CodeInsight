#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>H(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>H[i];
  }
  for(int i=N-1;i>0;i--){
  
    if(H[i-1]-H[i]==1){
    
      H[i-1]--;
    }
    if(H[i]>=H[i-1]){
    
      
    }
    else {
      cout<<"No";
      return 0;
    }
  }
  cout<<"Yes";
  return 0;
}
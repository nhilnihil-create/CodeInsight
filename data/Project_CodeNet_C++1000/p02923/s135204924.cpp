#include <iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>H(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>H[i];
  }
  int ans=0;
  int max=0;
  for(int i=0;i<=N-2;i++){
  
    if(H[i]>=H[i+1])max++;
    else{
      if(max>ans)ans=max;
      max=0;
    }
  }
  if(max>ans)ans=max;
  cout<<ans;
  return 0;
}
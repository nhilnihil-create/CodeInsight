#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,ans=0,count=0;
  cin>>N;
  vector<int> H(N);
  for(int i=0;i<N;i++)
    cin>>H.at(i);
  for(int i=0;i<N-1;i++){
    if(H.at(i)>=H.at(i+1)){
      count++;

    }
    else{
      ans=max(ans,count);
      count=0;
    
      
    }
    
  }
  cout<<max(ans,count)<<endl;
}
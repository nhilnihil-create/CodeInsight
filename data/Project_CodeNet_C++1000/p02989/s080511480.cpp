#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  sort(vec.begin(),vec.end());
  
  int x=vec[(N-1)/2];
  int y=vec[(N-1)/2+1];
  
  int ans=-1;
  
  if(x==y){
    cout<<0<<endl;
  }
  else{
  for(int i=x;i<=y;i++){
    ans++;
  }
  cout<<ans<<endl;
  }
}
#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,K;cin>>N>>K;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  int ans=0;
  for(int i=0;i<N;i++){
    if(vec[i]>=K){
      ans++;
    }
    else{
      ans=ans;
    }
  }
  cout<<ans<<endl;
}
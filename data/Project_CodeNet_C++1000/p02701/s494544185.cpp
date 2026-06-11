#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;cin>>N;
  vector<string> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  sort(vec.begin(),vec.end());
  
  int ans=N;
  
  for(int i=0;i<N;i++){
    if(vec[i]==vec[i+1]){
      ans--;
    }
  }
  
  cout<<ans<<endl;
}
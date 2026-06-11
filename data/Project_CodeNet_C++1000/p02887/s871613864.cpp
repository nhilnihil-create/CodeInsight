#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<char> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }

  int ans=1;
  
  
  for(int i=0;i<N-1;i++){
    if(vec[i+1]!=vec[i]){
      ans++;
    }
  }
  
  cout<<ans<<endl;
}
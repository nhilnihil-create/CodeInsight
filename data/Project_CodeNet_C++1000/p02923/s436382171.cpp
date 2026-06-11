#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  
  int ans=0;
  
  int x=0;
  
  
  for(int i=0;i<N-1;i++){
    if(H[i]>=H[i+1]){
      x++;
      ans=max(ans,x);
    }
    else{
      ans=max(ans,x);
      x=0;
    }
  }
  
  cout<<ans<<endl;
}